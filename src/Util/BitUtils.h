#pragma once

namespace Ciri {
	static inline uint8_t rotl8(uint8_t n, unsigned int c)
	{
		const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);
		c &= mask;
		return (n << c) | (n >> ((-c) & mask));
	}

	static inline uint8_t rotr8(uint8_t n, unsigned int c)
	{
		const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);
		c &= mask;
		return (n >> c) | (n << ((-c) & mask));
	}

	static inline uint8_t sra8(uint8_t n)
	{
		const uint8_t mask = 0x10;
		uint8_t sign = n & 0x10;
		return (n >> 1) | sign;
	}
}