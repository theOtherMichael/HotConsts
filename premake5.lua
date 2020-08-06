--[[
    HotConsts Premake Script
    To run this script for your platform, run scripts/buildlib_win.bat (Windows) or 
    scripts/buildlib_mac.command (macOS).

    When you build this script, the library project will be generated in the root directory.
    You can link to this project from your workspace/solution.
]]

local configurationName = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "HotConsts"
    language "C++"
    cppdialect "C++17"

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"
    filter "system:macosx"
        systemversion "10.15"
    filter {}
    
    configurations { "Debug", "Release" }
    filter "configurations:Debug"
        symbols "On"
    filter "configurations:Release"
        optimize "On"
    filter {}
    
    platforms { "Static64", "Static32" }
    filter "platforms:Static64"
        architecture "x86_64"
    filter "platforms:Static32"
        architecture "x86"
    filter {}

    startproject "HotConsts_Tests"

-- Library project.
project "HotConsts"
    kind "StaticLib"
    files { "include/HotConsts/**.h", "src/**.cpp" }

    includedirs "include/HotConsts"
    pchheader "HC_PCH.h"
    filter "system:macosx"
        pchheader "include/HotConsts/HC_PCH.h"
    filter {}
    pchsource "src/HC_PCH.cpp"
    targetdir ("bin/" .. configurationName .. "/%{prj.name}")
    objdir ("bin-int/" .. configurationName .. "/%{prj.name}")

-- Test project.
project "HotConsts_Tests"
    kind "ConsoleApp"
    location "tests"
    
    links "HotConsts"
    files { "tests/**.h", "tests/**.cpp" }
    
    sysincludedirs "include"
    targetdir ("tests/bin/" .. configurationName .. "/%{prj.name}")
    objdir ("tests/bin-int/" .. configurationName .. "/%{prj.name}")
    debugdir "tests/"

    defines { "HOTCONSTS_DEBUG", "NOMINMAX" }
