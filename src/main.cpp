#include "ciripch.h"

void InitLogger()
{
	Ciri::Log::InitLogger();
	CI_INFO("Initialised Logger");
}

int main()
{
	std::cin.get();
	return 0;
}