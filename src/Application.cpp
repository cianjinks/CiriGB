#include "ciripch.h"

#include "Application.h"
#include "ImGui/ImGuiHandler.h"
#include "OpenGL/GLFrameBuffer.h"

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

		m_Emulator = new Emulator();

		while (!glfwWindowShouldClose(m_Window)) {
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.25f, 0.25f, 0.25, 1.0f);

			Ciri::ImGuiHandler::NewFrame();
			//ImGui::ShowDemoWindow();

			// Debug Window
			ImGui::SetNextWindowSize(/**ImVec2(m_Emulator->GetEmulatorWidth(), m_Emulator->GetEmulatorHeight())**/ImVec2(200.0f, 100.0f));
			ImGui::Begin("Emulator");
			//if (ImGui::Button("Run"))
			{
				m_Emulator->Run();
			}
			ImGui::End();

			// Testing GPU draw to window
			ImGui::SetNextWindowSize(ImVec2(m_Emulator->GetEmulatorWidth(), m_Emulator->GetEmulatorHeight()));
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
			ImGui::Begin("Screen");

			ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
			ImVec2 viewportSize = { viewportPanelSize.x, viewportPanelSize.y };

			uint64_t textureID = m_Emulator->GetScreen();
			ImGui::Image(reinterpret_cast<void*>(textureID), ImVec2{ viewportSize.x, viewportSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
			ImGui::End();
			ImGui::PopStyleVar();

			Ciri::ImGuiHandler::Render();

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		glfwDestroyWindow(m_Window);
		glfwTerminate();
		delete m_Emulator;
	}
}