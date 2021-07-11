workspace "CGameEngine"
	architecture "x86_64"
	configurations { "Debug", "Release" ,"Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

InlcudeDir = {}
InlcudeDir["Glad"]="CGameEngine/vendor/GLFW/include"
InlcudeDir["GLAD"]="CGameEngine/vendor/Glad/include"
InlcudeDir["Imgui"]="CGameEngine/vendor/imgui"

include "CGameEngine/vendor/GLFW"
include "CGameEngine/vendor/Glad"
include "CGameEngine/vendor/Imgui"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-bin/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"CGameEngine/vendor/spdlog/include",
		"CGameEngine/src",
	}

	links
	{
		"CGameEngine"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CL_PLATFORM_WINDOWS",
			"CL_ENABLE_ASSERTS",
			"CRYSTAL_SYSTEM_API_CRYSTAL"
		}


	filter "configurations:Debug"
		defines "CG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CG_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CG_DIST"
		symbols "On"


project "CGameEngine"
	location "CGameEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-bin/" .. outputdir .. "/%{prj.name}")

	pchheader "cpch.h"
	pchsource "CGameEngine/src/cpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",		
		"%{prj.name}/vendor/spdlog/include",
	}

	includedirs
	{
		"CGameEngine/vendor/spdlog/include",
		"CGameEngine/src",
		"CGameEngine/vendor/GLFW/include",
		"CGameEngine/vendor/Glad/include",
		"CGameEngine/vendor/imgui",
	}

	links
	{
		"GLFW",
		"ImGui",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CL_PLATFORM_WINDOWS",
			"CRYSTAL_BUILD_DLL",
			"CL_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE",
			"CRYSTAL_SYSTEM_API_CRYSTAL"
		}

		postbuildcommands
		{
			{"{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox" }
		}

	filter "configurations:Debug"
		defines "CG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CG_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "CG_DIST"
		symbols "On"



