#include "ciripch.h"

#include "Cpu/Cpu.h"

void InitLogger()
{
	Ciri::Log::InitLogger();
	CI_INFO("Initialised Logger");
}

void CPUTest()
{
	Ciri::CPU cpu;
	while (true)
	{
		cpu.Run();
	}
	
}

int main()
{
	CPUTest();
	std::cin.get();
	return 0;
}