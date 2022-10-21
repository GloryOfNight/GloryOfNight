Minimize amount of move and copy by using std::forward, case study from: [Moving Faster: Everyday Efficiency in Modern C++](https://youtu.be/LFv7XwgsdLY?t=2087 )


std::forward allows you to pass the template arguments to other places, like object constructors without extra moves and copies.  
It also makes life easier since you not relying on constructor arguments in your template and that making code more flexible.

```
#include <utility>
#include <string>
#include <vector>

struct foo
{
	// bad constructor, due to string s being constructed multiple times
	//foo(int i, double d, char c, const std::string& s)
	//	: _i{ i }, _d{ d }, _c{ c }, _s{ s }
	//{}

	// not good constructor, string no longer constructed multiple times. But move still isn't free
	//foo(int i, double d, char c, std::string&& s)
	//	: _i{ i }, _d{ d }, _c{ c }, _s{ s }
	//{}

	// good constructor, string no longer constructed multiple times and move is free
	template<typename STR>
	foo(int i, double d, char c, STR&& s)
		: _i{ i }, _d{ d }, _c{ c }, _s{ std::forward<STR>(s) }
	{}
	
	int _i;
	double _d;
	char _c;
	std::string _s;
};

class bar
{
	std::vector<foo> foos;
public:
	// same thing, foo gets constructed once and free move
	template<typename... T>
	void add(T&&... t)
	{
		foos.emplace_back(std::forward<T>(t)...);
	}
};

int main()
{
	bar b;
	b.add(1, 3.14, 'c', "string");
	return 0;
}
```