#pragma once

namespace Ciri
{
	class RAM
	{
	private:
		uint8_t* m_Data = nullptr;

	public:
		RAM()  { m_Data = new uint8_t[0x10000]; }
		~RAM() { delete m_Data; }

		void setByte(uint16_t address, uint8_t byte);
		uint8_t getByte(uint16_t address);
	};
}