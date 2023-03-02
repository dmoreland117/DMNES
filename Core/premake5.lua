project "Core"
    kind "staticLib"
    language "c++"
    
    -- dirs
    targetdir ("lib/%{cfg.buildcfg}-%{cfg.architecture}")
    objdir ("lib/obj/%{cfg.buildcfg}-%{cfg.architecture}")

    -- include all cpp and h files in the project
    files
    {
        "include/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "include"
    }

    -- stuff for windows builds
    filter "system:windows"
        cppdialect "c++17"
        staticruntime "on"
        systemversion "latest"

        defines 'WINDOWS'
    
    -- set up configurations
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"
    filter "configurations:Release"
        defines "RELEASE"
        optimize "on"
