#include "ciripch.h"

#include "MemoryUnit.h"
namespace Ciri
{
	void MemoryUnit::setByte(uint32_t address, uint8_t value)
	{
		if (address >= m_VideoRAM.m_StartPosition && address < m_VideoRAM.m_EndPosition)
		{
			// Video RAM
			m_VideoRAM.setByte(address, value);
			CI_WARN("Wrote to Video RAM: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= m_ExternalRAM.m_StartPosition && address < m_ExternalRAM.m_EndPosition)
		{
			// External RAM
			m_ExternalRAM.setByte(address, value);
			CI_WARN("Wrote to External RAM: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= m_InternalRAM.m_StartPosition && address < m_InternalRAM.m_EndPosition)
		{
			// Internal RAM
			m_InternalRAM.setByte(address, value);
			CI_WARN("Wrote to Internal RAM: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= m_OAMRAM.m_StartPosition && address < m_OAMRAM.m_EndPosition)
		{
			// OAM RAM
			m_OAMRAM.setByte(address, value);
			CI_WARN("Wrote to OAM RAM: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= m_IORegisters.m_StartPosition && address < m_IORegisters.m_EndPosition)
		{
			// IO Registers
			m_IORegisters.setByte(address, value);
			CI_WARN("Wrote to IO Registers: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= m_HighRAM.m_StartPosition && address < m_HighRAM.m_EndPosition)
		{
			// High RAM
			m_HighRAM.setByte(address, value);
			CI_WARN("Wrote to High RAM: 0x{0:x} = 0x{1:x}", address, value);
		}
		else if (address >= 0x00 && address <= 0xFF)
		{
			// Boot Rom
			CI_ASSERT(false, "Attempted to write to Boot ROM");
		}
		else
		{
			CI_ERROR("RAM Write in Invalid Region: 0x{0:x} = 0x{1:x}", address, value);
			CI_ASSERT(false, "");
		}
	}

	uint8_t MemoryUnit::getByte(uint32_t address)
	{
		if (address >= m_VideoRAM.m_StartPosition && address < m_VideoRAM.m_EndPosition)
		{
			// Video RAM
			return m_VideoRAM.getByte(address);
		}
		else if (address >= m_ExternalRAM.m_StartPosition && address < m_ExternalRAM.m_EndPosition)
		{
			// External RAM
			return m_ExternalRAM.getByte(address);
		}
		else if (address >= m_InternalRAM.m_StartPosition && address < m_InternalRAM.m_EndPosition)
		{
			// Internal RAM
			return m_InternalRAM.getByte(address);
		}
		else if (address >= m_OAMRAM.m_StartPosition && address < m_OAMRAM.m_EndPosition)
		{
			// OAM RAM
			return m_OAMRAM.getByte(address);
		}
		else if (address >= m_IORegisters.m_StartPosition && address < m_IORegisters.m_EndPosition)
		{
			// IO Registers 
			return m_IORegisters.getByte(address);
		}
		else if (address >= m_HighRAM.m_StartPosition && address < m_HighRAM.m_EndPosition)
		{
			// High RAM
			return m_HighRAM.getByte(address);
		}
		else if (address >= 0x00 && address <= 0xFF)
		{
			// Boot Rom
			return m_BootRom.getByte(address);
		}
		else if (address >= 0x100 && address < 0x8000)
		{
			// Rest of ROM Address Space
			CI_WARN("Read from ROM address space (which is currently empty)");
		}
		else
		{
			CI_ASSERT(false, "Memory Read in Invalid Region");
		}
	}
}