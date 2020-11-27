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
			H = (uint8_t)(hl & 0x00FF);
			L = (uint8_t)((hl & 0xFF00) >> 8);
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
			B = (uint8_t)(bc & 0x00FF);
			C = (uint8_t)((bc & 0xFF00) >> 8);
		}

		uint16_t getDE()
		{
			return (uint16_t)D | ((uint16_t)E) << 8;
		}

		void setDE(uint16_t de)
		{
			D = (uint8_t)(de & 0x00FF);
			E = (uint8_t)((de & 0xFF00) >> 8);
		}

		uint16_t getAF()
		{
			return (uint16_t)A | ((uint16_t)F) << 8;
		}

		void setAF(uint16_t af)
		{
			A = (uint8_t)(af & 0x00FF);
			F = (uint8_t)((af & 0xFF00) >> 8);
		}

		// Flags
		bool getZFlag()
		{
			return ((F & 0x80) >> 7) == 1;
		}

		void setZFlag(bool value)
		{
			if (value) { F = F | ((uint8_t)0x01 << 7); }
			else { F = F & ~((uint8_t)0x1 << 7); }
		}

		bool getNFlag()
		{
			return ((F & 0x40) >> 6) == 1;
		}

		void setNFlag(bool value)
		{
			if (value) { F = F | ((uint8_t)0x01 << 6); }
			else { F = F & ~((uint8_t)0x1 << 6); }
		}

		bool getHFlag()
		{
			return ((F & 0x20) >> 5) == 1;
		}

		void setHFlag(bool value)
		{
			if (value) { F = F | ((uint8_t)0x01 << 5); }
			else { F = F & ~((uint8_t)0x1 << 5); }
		}

		bool getCFlag()
		{
			return ((F & 0x10) >> 4) == 1;
		}

		void setCFlag(bool value)
		{
			if (value) { F = F | ((uint8_t)0x01 << 4); }
			else { F = F & ~((uint8_t)0x1 << 4); }
		}
	};
}
