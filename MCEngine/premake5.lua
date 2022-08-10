project "MCEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir("$(SolutionDir)" .. outputdir .. "/bin//%{prj.name}")
    objdir("$(SolutionDir)" .. outputdir .. "/bin-int/%{prj.name}")
    
    files {
        "**.cpp",
        "**.h"
    }
    
    includedirs {}

    pchheader "PCH.h"
    pchsource "./src/PCH.cpp"

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
        defines{"WIN_OS","BUILD_DLL"}

        postbuildcommands { 
            "{MKDIR}  $(SolutionDir)" .. outputdir .. "/bin/MCGame",  
            "{COPY} %{cfg.buildtarget.relpath} $(SolutionDir)" .. outputdir .. "/bin/MCGame"
        }