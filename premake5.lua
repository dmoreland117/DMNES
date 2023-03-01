workspace "DMNES"  
    architecture "x64"
    configurations { "Debug", "Release" } 

    startproject 'SDL2_UI'

coreOutputDir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "Core"
    -- the project folder
    location "%{prj.name}"
    kind "staticLib"
    language "c++"

    -- output and intermediat dirs
    targetdir ("Core/lib/" .. coreOutputDir)
    objdir ("Core/lib/obj/" .. coreOutputDir)

    -- include all cpp and h files in the project
    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/include"
    }

    -- stuff fore windows builds
    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        defines'WINDOWS'
    
    -- set up configurations
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "on"

-- the main project
project "SDL2_UI"
    location "%{prj.name}"
    kind "ConsoleApp"
    language "c++"

    -- output and intermediat dirs
    -- example : bin/Debug/x64/SDL2_UI.exe
    targetdir ("bin/%{cfg.buildcfg}-%{cfg.architecture}")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.architecture}")

    -- include all cpp and h files in the project
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Core/include"
    }

    links "Core"

    -- stuff fore windows builds
    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        defines'WINDOWS'
    
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "on"

newaction
{
    trigger = "clean",
    description = "Clean up Project files.",
    execute = function()
        print("Cleaning Project...")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.filters")
        print("Project cleaned.")
    end
}