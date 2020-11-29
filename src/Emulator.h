#pragma once
#include "Cpu/Cpu.h"

namespace Ciri {

	class Emulator
	{
	private:
		static float s_EmulatorWidth;
		static float s_EmulatorHeight;

	public:
		CPU m_CPU;

	public:
		float GetEmulatorWidth() { return s_EmulatorWidth; };
		float GetEmulatorHeight() { return s_EmulatorHeight; };
	};
}