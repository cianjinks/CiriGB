#pragma once

namespace Ciri
{
	class RAM
	{
	private:
		uint8_t* m_Data = nullptr;
	public:
		uint16_t m_Size = 0;
		uint16_t m_StartPosition = 0;
		uint16_t m_EndPosition = 0;
	private:
	public:
		RAM(uint16_t start, uint16_t size) : m_StartPosition(start), m_Size(size), m_EndPosition(start + size) { m_Data = new uint8_t[size]; }
		~RAM() { delete m_Data; }

		void setByte(uint16_t address, uint8_t byte);
		uint8_t getByte(uint16_t address);
	};
}