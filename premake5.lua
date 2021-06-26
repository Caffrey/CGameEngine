workspace "CGameEngine"
	architecture "x86_64"
	configurations { "Debug", "Release" ,"Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


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
		"CGameEngine/src"
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
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-bin/" .. outputdir .. "/%{prj.name}")

	pchheader "cpch.h"
	pchsource "CGameEngine/src/cpch.cpp"

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

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"CL_PLATFORM_WINDOWS",
			"CRYSTAL_BUILD_DLL"
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



