project "MCEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir("$(SolutionDir)" .. outputdir .. "/bin//%{prj.name}")
    objdir("$(SolutionDir)" .. outputdir .. "/bin-int/%{prj.name}")
    
    files {
        "./src/**.cpp",
        "./src/**.h"
    }

    includedirs {"$(SolutionDir)MCEngine/src"}

    externalincludedirs {
        "$(SolutionDir)MCEngine/external/spdlog/include"
    }

    externalwarnings "Off"

    pchheader "pch.h"
    pchsource "./src/pch.cpp"

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
        defines{"WIN_OS","BUILD_DLL"}

        postbuildcommands { 
            "{MKDIR}  $(SolutionDir)" .. outputdir .. "/bin/MCGame",  
            "{COPY} %{cfg.buildtarget.relpath} $(SolutionDir)" .. outputdir .. "/bin/MCGame"
        }