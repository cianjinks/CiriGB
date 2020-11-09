#include "ciripch.h"
#include "RAM.h"

namespace Ciri
{
	void RAM::setByte(uint16_t address, uint8_t byte)
	{
		m_Data[address] = byte;
	}

	uint8_t RAM::getByte(uint16_t address)
	{
		return m_Data[address];
	}
}