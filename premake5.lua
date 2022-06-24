workspace "MintCloud"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "MCEngine"

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "MCEngine"
include "MCGame"

newaction {
    trigger = "clean",
    description = "Remove all binaries and project files",
    execute = function()
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Remvoing binaries")
        os.rmdir("./bin")
    end
}