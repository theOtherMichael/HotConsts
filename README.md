# Hot Constants

Hot Constants allows you to create hot-reloadable constants in your C++ code.  Here's how it works:

1. Declare a hot constant with the `HC()` macro and assign it a value:
```cpp
HC(int, exampleConstant) = 1;
```
2. Use the value in your code like you would any other `const` variable:
```cpp
int additionResult = exampleConstant + 1;
```
3. During debugging, change the assigned value in the source file and save it.  The value is reloaded instantly.
```
[std::cout]
Hot Constants:  Reloading file "main.cpp".
Hot Constants:  "exampleConstant" sucessfully reloaded!
```

In debug builds, you can tweak the constants and test the results without having to recompile or relaunch your program.  In release builds, the macros evaluate into hard-coded constants.

Hot Constants was developed with game programming in mind, to bring the flexibility of tweak/INI files to your entire project.  Now, you can tweak hard-coded constants in real-time without JIT compilers, script files, or separate data files.

## How do it do?

In debug builds, the `HC()` macro does the following things:

1. It creates an atomic variable and registers it with the reload mechanism.
2. It declares a `const` reference to the variable, which can be used just like any other constant.
3. During static initialization, it launches a thread to watch each of your source files for changes.

This idea was inspired by Tweakable Constants, a concept discussed in [a post on gamedev.net](https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/tweakable-constants-r2731/) by Joel Davis, who himself learned it from a [lost thread](https://mollyrocket.com/forums/viewtopic.php?p=3355) by Casey Muratori on MollyRocket.com.  The main difference between Tweakable Constants and Hot Constants is that Hot Constants is totally over-engineered: it's designed to be a robust tool you can plop into any project.

## Features

* **Named constants.**  You can use hot constants anywhere you'd use normal constants.
* **No refactoring.**  You can convert any named constant into a hot constant (and vice-versa) just by changing its declaration.
* **Externs.**  The `HCEX()` macro allows you to declare `extern` hot constants.
* **Expression evaluation**.  You can assign expressions to your hot constants. During a reload, assignment expressions are evaluated to the exact value your compiler would calculate.
    * Non-arithmetic expressions (strings) are not implemented yet but will be supported soon.
* **Simple to implement.**  Just link to the library, define `HOTCONSTS_DEBUG` in your debug builds, and include  `HotConsts\HotConsts.h` where you need it.

Currently, the reload mechanism has been implemented for Windows only.  macOS support is coming soon.

## How to Use It

To build the library project, run the appropriate script in *scripts/*.  The project *HotConsts* can then be included in your solution/workspace, and the *include* folder can be added to your include paths.

If you use Premake for your project's build system, you can link the library project to your Premake script by [including](https://github.com/premake/premake-core/wiki/include) `premake5.lua` in Hot Constants' root directory, then [linking](https://github.com/premake/premake-core/wiki/links) to `"HotConsts"`.

If you'd prefer to build the binaries directly, compile the HotConsts project in the root directory for your desired configuration.  The output folder is "bin" in the root directory.

Once you've linked the library to your project, define `HOTCONSTS_DEBUG` in configurations where you will use the reload feature, and include `HotConsts/HotConsts.h`.  Actually using Hot Constants is super simple: just use `HC(type, name)` to declare a constant, `HCEX(type, name)` to declare an `extern`.

### To-Do
* macOS support
* Full support for `char` literals
* Support for string constants
* Use of true atomics (non-locking) for viable types
* Misc. quality improvements

### Known Issues

* If you forget a semicolon (\";\") after a constant assignment, the next line will be skipped during a reload.
* If you break a string literal across multiple lines using a backslash (\"\\\"), Hot Constants may incorrectly parse the next line during a reload.

Hot Constants uses [Premake](https://premake.github.io/) for its build system.