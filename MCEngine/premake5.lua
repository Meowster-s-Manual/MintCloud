include "external/optick" 
include "external/glfw"

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

    includedirs {
        "C:/VulkanSDK/1.3.239.0/Include",
        "$(SolutionDir)MCEngine/src",
    }

    externalincludedirs {
        "$(SolutionDir)MCEngine/external/spdlog/include",
        "$(SolutionDir)MCEngine/external/optick/src",
        "$(SolutionDir)MCEngine/external/glfw/include",
        "$(SolutionDir)MCEngine/external/glm",
    }

    libdirs {
        "C:/VulkanSDK/1.3.231.1/Lib"
    }

    externalwarnings "Off"

    pchheader "pch.h"
    pchsource "./src/pch.cpp"

    links{
        "OptickCore",
        "GLFW",
        "vulkan-1.lib"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"
        defines{"WIN_OS","BUILD_DLL"}

        postbuildcommands { 
            "{MKDIR}  $(SolutionDir)" .. outputdir .. "/bin/MCGame",
            "{COPY} %{cfg.buildtarget.relpath} $(SolutionDir)" .. outputdir .. "/bin/MCGame"
        }