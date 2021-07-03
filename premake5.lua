workspace "Flip"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Flip"
	location "Flip"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fppch.h"
	pchsource "Flip/src/fppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FP_PLATFORM_WINDOWS",
			"FP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "FP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "FP_RELEASE"
			symbols "On"


		filter "configurations:dist"
			defines "FP_DIST"
			symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Flip/vendor/spdlog/include",
		"Flip/src"
	}

	links
	{
		"Flip"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FP_PLATFORM_WINDOWS"
		}


		filter "configurations:Debug"
			defines "FP_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "FP_RELEASE"
			symbols "On"


		filter "configurations:dist"
			defines "FP_DIST"
			symbols "On"