#include "ciripch.h"

#include "MemoryUnit.h"
namespace Ciri
{
	void MemoryUnit::setByte(uint32_t address, uint8_t value)
	{
		if (address >= 0x00 && address <= 0xFF)
		{
			// Boot Rom
			CI_WARN("Cannot write to ROM: 0x{0:x}", address);
		}
		else if (address >= 0xA000 && address < 0xC000)
		{
			// Internal Ram
			m_Ram.setByte((uint16_t)(address - 0xA000), value);
		}
		else if (address >= 0xFF80 && address < 0xFFFF)
		{
			// High RAM
			m_Ram.setByte((uint16_t)(address), value);
		}
		else
		{
			CI_WARN("Memory Access in unmapped region");
			//CI_ASSERT(false, "Memory Access Address out of range");
		}
	}

	uint8_t MemoryUnit::getByte(uint32_t address)
	{
		if (address >= 0x00 && address <= 0xFF)
		{
			// Boot Rom
			return m_BootRom.getByte((uint16_t)address);
		}
		else if (address >= 0xA000 && address < 0xC000)
		{
			// Internal Ram
			return m_Ram.getByte((uint16_t)(address - 0xA000));
		}
		else if (address >= 0xFF80 && address < 0xFFFF)
		{
			// High RAM
			return m_Ram.getByte((uint16_t)(address));
		}
		else
		{
			CI_WARN("Memory Access in unmapped region");
			//CI_ASSERT(false, "Memory Access Address out of range");
		}
	}
}