project "MCEngine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "**.cpp",
        "**.h"
    }
    
    includedirs {}

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
        defines {}