workspace "Ciri"
	architecture "x64"
	startproject "Ciri"
	
	configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "dependencies/GLFW"
	include "dependencies/glad"
	include "dependencies/imgui"
group ""

project "Ciri"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "ciripch.h"
	pchsource "src/ciripch.cpp"
	
	files
	{
		"src/**.h",
		"src/**.cpp",
		"dependencies/stb_image/**.h",
		"dependencies/stb_image/**.cpp",
		"dependencies/glm/glm/**.hpp",
		"dependencies/glm/glm/**.inl"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"dependencies/spdlog/include",
		"dependencies/GLFW/include",
		"dependencies/glad/include",
		"dependencies/imgui",
		"dependencies/glm",
		"dependencies/stb_image"
	}
	
	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CI_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CI_RELEASE"
		runtime "Release"
        optimize "on"