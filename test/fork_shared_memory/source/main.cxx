#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <mutex>
#include <sys/wait.h>

template <typename T>
struct TSharedMemory
{
    TSharedMemory()
    {
        Data = reinterpret_cast<T *>(mmap(nullptr, sizeof(T), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
        if (Data == MAP_FAILED)
        {
            Data = nullptr;
            std::cerr << "Failed to create shared memory" << std::endl;
            return;
        }

        new (Data) T();
    }

    TSharedMemory(const TSharedMemory &) = delete;
    TSharedMemory &operator=(const TSharedMemory &) = delete;

    ~TSharedMemory()
    {
        munmap(Data, sizeof(T));
    }

    T *operator->()
    {
        return Data;
    }

    bool IsValid() const { return Data != nullptr; }

private:
    T *Data;
};

struct SharedData
{
    std::mutex Mutex = {};
    int Value = 0;
    char Name[256] = {};
};

int main()
{
    TSharedMemory<SharedData> Data = {};

    pid_t pid = fork();
    if (pid < 0)
    {
        std::cerr << "Failed to fork" << std::endl;
        return 1;
    }
    else if (pid == 0)
    {
        std::cout << "Hello from child" << std::endl;

        std::lock_guard lock(Data->Mutex);
        std::cout << "Child aquired lock" << std::endl;

        Data->Value = getpid() ^ 42;
        Data->Name[0] = 'H';
        Data->Name[1] = 'e';
        Data->Name[2] = 'l';
        Data->Name[3] = 'l';
        Data->Name[4] = 'o';
    }
    else
    {
        std::cout << "Parent after fork" << std::endl;

        do
        {
            int Status = 0;
            const auto waitres = waitpid(-1, &Status, WNOHANG);
            if (waitres == -1)
            {
                std::cerr << "Failed to waitpid" << std::endl;
                return 1;
            }
            else if (waitres > 0)
            {
                std::cout << "Child exited pid " << waitres << std::endl;

                std::lock_guard lock(Data->Mutex);
                std::cout << "Child value: " << Data->Value << std::endl;
                std::cout << "Child name: " << Data->Name << std::endl;

                break;
            }
            sleep(1);

        } while (true);
    }
}