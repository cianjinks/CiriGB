#pragma once
#include "Cpu/Cpu.h"
#include "Gpu/Gpu.h"

namespace Ciri {

	class Emulator
	{
	private:
		static float s_EmulatorWidth;
		static float s_EmulatorHeight;

	public:
		Emulator() : m_GPU(160, 144) {}
		CPU m_CPU;
		GPU m_GPU;

	public:
		float GetEmulatorWidth() { return s_EmulatorWidth; };
		float GetEmulatorHeight() { return s_EmulatorHeight; };
	};
}