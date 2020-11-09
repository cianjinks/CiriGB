#pragma once
namespace Ciri
{
	struct RegisterFile
	{
		uint8_t A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, H = 0, L = 0;
		uint16_t SP = 0, PC = 0;
	};
}
