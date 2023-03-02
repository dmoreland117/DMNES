workspace "DMNES"  
    architecture "x64"
    configurations { "Debug", "Release" } 

    startproject "SDL2_UI"

-- Core project lib config
include("Core/premake5.lua")

-- the main project
include("SDL2_UI/premake5.lua")

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