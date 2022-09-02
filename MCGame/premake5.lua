project "MCGame"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir("$(SolutionDir)" .. outputdir .. "/bin//%{prj.name}")
    objdir("$(SolutionDir)" .. outputdir .. "/bin-int/%{prj.name}")

    files {
        "**.cpp",
        "**.h"
    }

    includedirs {
        "$(SolutionDir)MCEngine/include",
        "$(SolutionDir)MCEngine/external/spdlog/include"
    }

    links {
        "MCEngine"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
        defines{"WIN_OS"}
