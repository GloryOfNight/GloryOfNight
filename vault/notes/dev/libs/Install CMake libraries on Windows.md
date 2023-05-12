Small guide how to install (mostly) any cmake library on Windows.

# Installing SDL library on Windows

## Compiling binaries yourself

### Prerequisites:
- CMake
- Visual Studio
- CMD or Git Bash

### Steps:
1. Clone or download SDL repository: https://github.com/libsdl-org/SDL.git
2. Open CMD or Git Bash terminal as admin (might be helpfull in case of installing files to system drive).
3. Open downloaded or cloned SDL source code directory in terminal.
4. Enter: ``` cmake -S . -B build ```; That will launch cmake files generation.
5. After that: ```cmake --build build --config Release --target INSTALL```; That will launch library compilation process and installation.
6. When is done, all library files would be installed in directory specified in console log. Usually that is: ```C:\Program Files (x86)\SDL3```.
7. To finish. Open Start menu, type and open: "Edit environment variables for your system".
8. Find and open: Environment Variables
9. Find "System Variables" list and click "New" at the bottom.
10. Type, variable name: SDL2 or SDL3 depending on which version you using.
11. Click "Browse Directory" and open SDL folder that was installed by cmake earlier.
12. You might need PC restart and your IDE for changed to work. 


NOTE: If you have project with already generated CMake solution, for changes to occur you need to clear project CMake cache!
