# SDL Example
Since i tend to reinvent the wheel all the time when starting a project... I hope i can give my future self some guidance with it.


# Using it
## Preparation in three simple steps
1. Check out this Repository
2. Put [SDL Sources](https://github.com/libsdl-org/SDL/releases) into `thirdparty/SDL` so that `thirdparty/SDL/CMakeLists.txt` exists
3. Rename `example` in `CMakeLists.txt` to the new project name


# Building
1. Create a `build` folder (for out-of-source builds) and `cd` into it.
2. Configure CMake with `cmake ..`.
3. Build with `cmake --build .`