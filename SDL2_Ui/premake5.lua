project "SDL2_UI"
    kind "ConsoleApp"
    language "c++"

    -- output and intermediat dirs
    -- example : bin/Debug/x64/SDL2_UI.exe
    targetdir ("../bin/%{cfg.buildcfg}-%{cfg.architecture}")
    objdir ("../bin-int/%{cfg.buildcfg}-%{cfg.architecture}")

    -- include all cpp and h files in the project
    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "../Core/include"
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
