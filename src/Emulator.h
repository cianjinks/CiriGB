#pragma once
#include "Cpu/Cpu.h"
#include "Gpu/Gpu.h"

namespace Ciri {

	class Emulator
	{
	private:
		static float s_EmulatorWidth;
		static float s_EmulatorHeight;

	private:
		CPU* m_CPU;
		GPU* m_GPU;

	public:
		RegisterFile m_Registers;
		MemoryUnit m_MemoryUnit;

	public:
		Emulator();
		~Emulator();

		void Run();

	public:
		float GetEmulatorWidth() { return s_EmulatorWidth; };
		float GetEmulatorHeight() { return s_EmulatorHeight; };
		uint64_t GetScreen() { return m_GPU->GetGLTexture(); }
	};
}