#include "ciripch.h"

#include "Emulator.h"

namespace Ciri {

	float Emulator::s_EmulatorWidth = 160 * 4;
	float Emulator::s_EmulatorHeight = 144 * 4;

	Emulator::Emulator()
	{
		m_CPU = new CPU(m_Registers, m_MemoryUnit);
		m_GPU = new GPU(m_MemoryUnit, 160, 144);
	}

	Emulator::~Emulator()
	{
		delete m_CPU;
		delete m_GPU;
	}

	void Emulator::Run()
	{
		m_CPU->Run();
		m_GPU->Update();
	}
}