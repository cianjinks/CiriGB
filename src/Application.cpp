#include "ciripch.h"

#include "Application.h"
#include "ImGui/ImGuiHandler.h"

namespace Ciri {

	float Application::s_WindowWidth = 1280;
	float Application::s_WindowHeight = 720;

	void Application::Run()
	{
		if (!glfwInit())
		{
			CI_ASSERT(false, "Failed to initalise GLFW");
		}
		CI_INFO("Initialised GLFW");

		m_Window = glfwCreateWindow(s_WindowWidth, s_WindowHeight, "Ciri", NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			CI_ASSERT(false, "Failed to initalise Glad");
		}
		CI_INFO("Initialised Glad");

		// V-sync
		glfwSwapInterval(1);
		Ciri::ImGuiHandler::Init(m_Window);

		while (!glfwWindowShouldClose(m_Window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			Ciri::ImGuiHandler::NewFrame();
			//ImGui::ShowDemoWindow();
			ImGui::SetNextWindowSize(ImVec2(m_Emulator.GetEmulatorWidth(), m_Emulator.GetEmulatorHeight()));
			ImGui::Begin("Emulator");
			if (ImGui::Button("Run"))
			{
				m_Emulator.m_CPU.Run();
			}
			ImGui::End();
			Ciri::ImGuiHandler::Render();

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}