#pragma once
#include "ROM.h"
#include "RAM.h"

namespace Ciri
{

	class MemoryUnit
	{
	private:
		ROM m_BootRom;
		RAM m_Ram;
	public:
		MemoryUnit() : m_BootRom(ROM::s_BootRom, 0x100) {}

		void setByte(uint32_t address, uint8_t value);
		uint8_t getByte(uint32_t address);
	};
}