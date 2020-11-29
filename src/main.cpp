#include "ciripch.h"

#include "Application.h"

int main()
{
	Ciri::Log::InitLogger();
	CI_INFO("Initialised Logger");

	Ciri::Application* app = new Ciri::Application;
	app->Run();
	delete app;

	return 0;
}