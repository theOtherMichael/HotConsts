#[[
	HotConsts CMake
	Add this directory to your project's CMakeLists.txt with add_subdirectory().
	Link HotConsts::HotConsts to your executable with target_link_libraries().
]]#

cmake_minimum_required(VERSION 3.22)
project(HotConsts VERSION 1.0.0 LANGUAGES CXX)

set(HC_INCLUDE
	./include/HotConsts/HC_ArithmeticEval.h
	./include/HotConsts/HC_Atomic.h
	./include/HotConsts/HC_Enums.h
	./include/HotConsts/HC_FileWatch.h
	./include/HotConsts/HC_LiteralConversions.h
	./include/HotConsts/HotConsts.h
)

set(HC_SRC
	./src/HC_ArithmeticEval.cpp
	./src/HC_Enums.cpp
	./src/HC_FileWatch_macOS.cpp
	./src/HC_FileWatch_Win32.cpp
	./src/HC_LiteralConversions.cpp
	./src/HotConsts.cpp
)

# Library
add_library(HotConsts STATIC ${HC_INCLUDE} ${HC_SRC})
add_library(HotConsts::HotConsts ALIAS HotConsts)

# Includes
target_include_directories(HotConsts
	PUBLIC
		"include"
)

# Don't compile src for other platforms
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set_source_files_properties(
			./src/HC_FileWatch_macOS.cpp
		PROPERTIES
			HEADER_FILE_ONLY TRUE)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
	set_source_files_properties(
			./src/HC_FileWatch_Win32.cpp
		PROPERTIES
			HEADER_FILE_ONLY TRUE)
endif()

# Dependency linking
target_link_libraries(HotConsts
	PUBLIC
		"$<$<PLATFORM_ID:Darwin>:-framework CoreServices>"
)

target_compile_definitions(HotConsts
	PRIVATE
		$<$<PLATFORM_ID:Windows>:UNICODE>
		$<$<PLATFORM_ID:Windows>:_UNICODE>
)

# Build flags
target_compile_features(HotConsts PUBLIC cxx_std_17) # TODO: Eliminate C++17 requirement

# Tester app
get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)
	add_subdirectory(tests)
endif()
