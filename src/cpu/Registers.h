#pragma once

struct RegisterFile
{
	uint8_t A, B, C, D, E, F, H, L;
	uint16_t SP, PC;
};