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

		void setHL(uint16_t hl)
		{
			H = (uint8_t)(hl & 0x0011);
			L = (uint8_t)((hl & 0x1100) >> 8);
		}

		uint16_t decrementHL()
		{
			uint16_t hl = getHL();
			setHL(getHL() - 1);
			return hl;
		}

		uint16_t incrementHL()
		{
			uint16_t hl = getHL();
			setHL(getHL() + 1);
			return hl;
		}

		uint16_t getBC()
		{
			return (uint16_t)B | ((uint16_t)C) << 8;
		}

		void setBC(uint16_t bc)
		{
			B = (uint8_t)(bc & 0x0011);
			C = (uint8_t)((bc & 0x1100) >> 8);
		}

		uint16_t getDE()
		{
			return (uint16_t)D | ((uint16_t)E) << 8;
		}

		void setDE(uint16_t de)
		{
			D = (uint8_t)(de & 0x0011);
			E = (uint8_t)((de & 0x1100) >> 8);
		}

		uint16_t getAF()
		{
			return (uint16_t)A | ((uint16_t)F) << 8;
		}

		void setAF(uint16_t af)
		{
			A = (uint8_t)(af & 0x0011);
			F = (uint8_t)((af & 0x1100) >> 8);
		}
	};
}
