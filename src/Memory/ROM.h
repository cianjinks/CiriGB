#pragma once

namespace Ciri
{
	class ROM
	{
	private:
		uint8_t* m_Data = nullptr;
		// 16 bit max size as each rom bank is 16 kilobytes (Max Address: 0x4000)
		uint16_t m_Size = 0;

	public:
		ROM(uint8_t* data , uint16_t size) : m_Data(data) 
		{
			CI_ASSERT(size <= s_MaxBankSize, "ROM Bank Size too large");
			m_Size = size;
		}

		uint8_t getByte(uint16_t address);

	public:
		static uint8_t s_BootRom[];
		static uint16_t s_MaxBankSize;
	};
}