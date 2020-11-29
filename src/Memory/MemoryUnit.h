#pragma once
#include "ROM.h"
#include "RAM.h"

namespace Ciri
{

	class MemoryUnit
	{
	private:
		ROM m_BootRom;
		RAM m_VideoRAM, m_ExternalRAM, m_InternalRAM, m_OAMRAM, m_IORegisters, m_HighRAM;
	public:
		MemoryUnit() : m_VideoRAM(0x8000, 0x2000), m_ExternalRAM(0xA000, 0x2000), m_InternalRAM(0xC000, 0x4000), m_OAMRAM(0xFE00, 0xA0), m_IORegisters(0xFF00, 0x80), m_HighRAM(0xFF80, 0x7F),
			           m_BootRom(ROM::s_BootRom, 0x100) {}

		void setByte(uint32_t address, uint8_t value);
		uint8_t getByte(uint32_t address);
	};
}