project "MCGame"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++20"

    targetdir("../build/" .. outputdir .. "/%{prj.name}")
    objdir("../build-int/" .. outputdir .. "/%{prj.name}")

    files {
        "**.cpp",
        "**.h"
    }

    includedirs {
        "$(SolutionDir)MCEngine"
    }