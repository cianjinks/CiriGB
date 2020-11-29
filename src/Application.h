#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Emulator.h"

namespace Ciri {

	class Application
	{
	private:
		GLFWwindow* m_Window;
		Emulator m_Emulator;

		static float s_WindowWidth;
		static float s_WindowHeight;
	public:
		void Run();

		GLFWwindow* GetWindow() { return m_Window; };
		float GetWindowWidth() { return s_WindowWidth; };
		float GetWindowHeight() { return s_WindowHeight; };
	};
}