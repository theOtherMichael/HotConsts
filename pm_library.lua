--[[
    Hot Constants Library Premake Script

    Builds the library project for the Hot Constants static library.  To build
    the library directly, run the appropriate script for your platform from the 
    "scripts" folder, then build the HotConsts_dev solution from the "tests" 
    folder.
    
    To invoke this script directly in your own project's premake script, include
    this file using "include", then use "configmap" to ensure your
    configurations and platforms line up correctly.
]]

local configurationName = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HotConsts"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    -- Platform-specific build settings
    filter "system:windows"
        systemversion "latest"
        staticruntime "Off"
    filter "system:macosx"
        systemversion "10.15"
    filter {}

    -- Build locations
    targetdir ("bin/" .. configurationName .. "/%{prj.name}")
    objdir ("bin-int/" .. configurationName .. "/%{prj.name}")

    -- Configurations
    filter "configurations:Debug"
        symbols "On"
    filter "configurations:Release"
        optimize "On"
    filter {}
    
    -- Platforms
    filter "platforms:Static64"
        architecture "x86_64"
    filter "platforms:Static32"
        architecture "x86"
    filter {}
    
    -- Files/Includes/Defines
    files { "include/HotConsts/**.h", "src/**.cpp" }
    includedirs "include/HotConsts"
        
    -- Precompiled header
    pchheader "HC_PCH.h"
    pchsource "src/HC_PCH.cpp"
    filter "system:macosx"
        pchheader "include/HotConsts/HC_PCH.h"
    filter {}
