# Hot Constants

Hot Constants allows you to create hot-reloadable constants in your C++ code.  Here's how it works:

1. Declare a hot constant with the `HC()` macro and assign it a value:
```cpp
HC(float, playerJumpHeight) = 5.0f;
```
2. Use the value in your code like you would any other `const` variable:
```cpp
playerPosY += playerJumpHeight;
```
3. While debugging, change the value in your source file and save it.
```
[std::cout]
Hot Constants:  Reloading file "main.cpp".
Hot Constants:  "playerJumpHeight" sucessfully reloaded!
```
4. The value will immediately update in your running program.

In release builds, the `HC()` macro evaluates to a simple constant declaration, eliminating the reload mechanism in shipping code.  This makes it perfectly safe to leave in your project long-term, as there will be zero overhead in shipped code.

```cpp
[Source file]
HC(float, playerJumpHeight) = 5.0f;

[Preprocessor output in Debug]
const HotConsts::HC_Atomic<float>& playerJumpHeight = HotConsts::_registerHotConst<float>("path/to/source/file", "playerJumpHeight", "float") = 5.0f;

[Preprocessor output in Release]
const float playerJumpHeight = 5.0f;
```

Hot Constants was designed with game development in mind, but it is suitable in any situation where hard-coded values are subject to change.  With Hot Constants, you can painlessly test new values on a whim, knowing that they will revert to hard-coded constants in release builds.

## Features

* **No refactoring needed.**  You can convert constants into hot constants (and back again) just by changing their declaration*.
* **Expression reloading**.  Hot Constants will automatically evaluate and reload any expression containing literals (e.g. `HC(double, frameDelta) = 1.0 / 60.0` is valid code).
* **Externs.**  The `HCEX()` macro allows you to declare extern hot constants, so you can reload constants across translation units.
* **Mac and Windows support.**  HotConsts has been tested on MSVC and Clang on macOS and Windows.

\* The one exception to this is template deduction, which will not deduce the base constant type.  Manual casting is required in these cases.

## How does it work?

When `HC_RELOADING_ON` is defined, `HC()` does the following:

1. A thread-safe variable is created, and a const reference to it is returned.
2. A thread is launched to monitor changes to the source file (if it doesn't already exist).
3. When you save changes to the source file, the watcher thread parses the new value and updates the corresponding variable.

On Windows, one thread is used per source file, and on Mac, one is used per source directory.  The threads sleep until the OS notifies them of a change: they don't "busy wait".

## How to use it

### CMake users

Hot Constants is powered by CMake.  To include it in your CMake project:

1. Clone this repository to a subdirectory of your project root.
2. Add the HotConsts directory to CMakeLists.txt using `add_subdirectory()`.
3. Link `HotConsts::HotConsts` to your executable using `target_link_libraries()`.
4. Define `HC_RELOADING_ON` in your debug builds.
5. Include `<HotConsts/HotConsts.h>` in files where you wish to use hot constants.

### Non-CMake users

Non-CMake users can simply add the source files to their projects directly:

1. Add every file in 'src' to your source files, except for "HC_FileWatch_macOS.cpp" on Windows and "HC_FileWatch_Win32.cpp" on Mac.
2. Add 'include' to your include path.
3. (*macOS only*) Link to the *CoreServices* framework.
4. (*Windows only*) Define `UNICODE` and `_UNICODE` (Visual Studio usually does this for you).
5. Define `HC_RELOADING_ON` in your debug builds.
6. Include `<HotConsts/HotConsts.h>` in files where you wish to use hot constants.

## Limitations

* At present, only C++17 projects are supported.  Support for C++11 and C++20 will be added if people find it useful.
* Only arithmetic types (integer, char, or floating-point) can be reloaded.
* Hot Constants cannot reload expressions containing other constant names or macros.
* Hot constants declared in explicitly-linked DLL/SO modules have not been tested.  Unloading a module containing the `HC()` macro may cause unexpected behavior.
* The reload mechanism is locking.  I can look at reducing locks if it becomes a problem.
* The library is currently static only: I have no plans for a shared/DLL version.

## Known Issues

* Character literals containing a space (`' '`) are not parsed correctly, and will not reload.
* If you accidentally remove a semicolon while tweaking a file, Hot Constants will fail to reload any `HC()` macros on the following line.
* If an `HC()` macro is preceded by a string literal broken across multiple lines with a backslash, it may not reload correctly.

## Test-driven development

If you wish to work on Hot Constants yourself, a basic test runner is available in 'tests'.  In CMake, simply configure a build tree from the root directory, then build and run the "HotConsts_Tester" target from the 'tests' folder.

---

Hot Constants was inspired by Tweakable Constants, a concept discussed in [a post on gamedev.net](https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/tweakable-constants-r2731/) by Joel Davis, who himself learned it from a [lost thread](https://mollyrocket.com/forums/viewtopic.php?p=3355) by Casey Muratori on MollyRocket.com.
