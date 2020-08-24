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
3. While debugging, change the assigned value in your source file and save it.  The new value will immediately be reflected in your program.
```
[std::cout]
Hot Constants:  Reloading file "main.cpp".
Hot Constants:  "exampleConstant" sucessfully reloaded!
```

This allows you to tweak hard-coded values live.  The reload mechanism is automatically stripped out of distribution builds, so Hot Constants ultimately has zero performance costs in your projects.  Once Hot Constants is set up, it's painless to use, and it requires no cleanup at all for your distribution builds.

Hot Constants was developed with game development in mind.  The idea is that you no longer have to set up data files or hot-reloadable code to tweak gameplay constants live.  This is for values which *should* be hard-coded but are nonetheless tweaked a lot over the life of a project (such as player jump height, or physics constants).

## Features

* **Named constants.**  You can use hot constants anywhere you'd use normal constants.
* **No refactoring.**  You can convert any named constant into a hot constant (and vice-versa) just by changing its declaration.
* **Externs.**  The `HCEX()` macro allows you to declare `extern` hot constants.
* **Expression evaluation**.  If you assign an expression to a hot constant, it will automatically be evaluated correctly during a reload.
* **Simple to implement.**  Just link to the library, define `HOTCONSTS_DEBUG` in your debug builds, and include  `HotConsts\HotConsts.h` where you need it.

Currently, the reload mechanism has been implemented for Windows only.  macOS support is coming soon.

## How Do It Do?

In debug builds, the `HC()` macro does the following things:

1. It creates an atomic* variable and registers it with the reload mechanism.
2. It declares a `const` reference to the variable, which can be used just like any other constant.
3. While your application runs, watcher threads trigger a reload if they detect changes to your source files.

\* For types which can't be atomic, a self-locking wrapper type is used instead.

## How to Use It
### 1. Build the Library
#### For Premake users

Hot Constants uses [Premake](https://premake.github.io/) for its build system.  If your project uses Premake as well, you can include the library project in your solution/workspace by using Premake's [`include`](https://github.com/premake/premake-core/wiki/include) command on *pm_library.lua*, which is located in the root directory.  For an example of how to do this, check out the *premake5.lua* file in the [Enterprise Engine repository](https://github.com/theOtherMichael/Enterprise).

Additionally, the *HotConsts* project uses the configurations *"Debug"* and *"Release"* for compiler optimizations and the platforms *"Static64"* and *"Static32"* to determine architecture.  You can use Premake's [`configmap`](https://github.com/premake/premake-core/wiki/configmap) command to map these to the configurations used in your solution/workspace.

#### For non-Premake users

To build the library project, run the appropriate script for your platform in the *scripts* folder.  You can then include the project *HotConsts* in your solution/workspace.  The library project will be located in the *HotConsts* root directory.

If you wish to simply compile the binaries and link to them manually, open `HotConsts_dev` from the *tests* folder and compile for your configuration.  The binary will be generated in the *bin* folder of the root directory, which can then be linked to your project.  As Hot Constants is still very new, I'd recommend including the project file instead.

### 2. Add the Include Path

Add the *include* folder to your project's include paths.

### 3. Define `HOTCONSTS_DEBUG` in Appropriate Configurations

To use the reload mechanism, you'll need to define `HOTCONSTS_DEBUG` in any configurations where you want your code to be reloadable.  This isn't necessarily the same thing as your debug build: for example, in Enterprise Engine, `HOTCONSTS_DEBUG` is defined in both the *Debug* and *Release* builds (but not *Dist* builds), so that values can be tweaked even in optimized code.

### 4. Include `HotConsts.h` and Start Using it!

Wherever you use Hot Constants, include `HotConsts/HotConsts.h`.  You can then use `HC(type, name)` to declare a constant, and `HCEX(type, name)` to declare an `extern` one.

Hot Constants uses `std::cout` to output debug messages, which can be helpful if your constants aren't reloading as expected.  To see them, ensure that you can see the output of the standard C output stream in your application.

## To-Do
* macOS reload mechanism
* Full support for `char` literals
* Support for string constants
* Use of true atomics (non-locking) for viable types
* C++ 20 support
* Misc. quality improvements

## Known Issues

* If you forget a semicolon (\";\") after a constant assignment, the next line of code will be skipped during a reload.  If the skipped line contains a hot constant declaration, it will not be reloaded.
* If you break a string literal across multiple lines using a backslash (\"\\\"), Hot Constants may incorrectly parse the next line during a reload.

Hot Constants was inspired by Tweakable Constants, a concept discussed in [a post on gamedev.net](https://www.gamedev.net/tutorials/programming/general-and-gameplay-programming/tweakable-constants-r2731/) by Joel Davis, who himself learned it from a [lost thread](https://mollyrocket.com/forums/viewtopic.php?p=3355) by Casey Muratori on MollyRocket.com.