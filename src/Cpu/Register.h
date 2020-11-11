#pragma once
namespace Ciri
{
	struct RegisterFile
	{
		uint8_t A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, H = 0, L = 0;
		uint16_t SP = 0, PC = 0;

		// These could have wrong endian
		uint16_t getHL()
		{
			return (uint16_t)H | ((uint16_t)L) << 8;
		}

		uint16_t getBC()
		{
			return (uint16_t)B | ((uint16_t)C) << 8;
		}

		uint16_t getDE()
		{
			return (uint16_t)D | ((uint16_t)E) << 8;
		}
	};
}
