#pragma once
#include "Register.h"
#include "Memory/MemoryUnit.h"
#include "Instruction.h"

#define CI_TO16(x, y) (uint16_t)x | (((uint16_t)y) << 8)

namespace Ciri
{
	class CPU
	{
	private:
		InstructionSet m_InstructionSet;
		InstructionSet m_CBInstructionSet;
		RegisterFile& m_Registers;
		MemoryUnit& m_MemoryUnit;

	public:
		CPU(RegisterFile& registers, MemoryUnit& memoryunit);

		void Run();

		uint8_t addBytes(RegisterFile& rf, uint8_t byte1, uint8_t byte2);
		uint16_t addBytes16(RegisterFile& rf, uint16_t byte1, uint16_t byte2);
		uint8_t addBytesWithCarry(RegisterFile& rf, uint8_t byte1, uint8_t byte2);
		uint8_t subBytes(RegisterFile& rf, uint8_t byte1, uint8_t byte2);
		uint8_t subBytesWithCarry(RegisterFile& rf, uint8_t byte1, uint8_t byte2);
		uint8_t increment(RegisterFile& rf, uint8_t byte);
		uint8_t decrement(RegisterFile& rf, uint8_t byte);
		uint16_t jmpPC(uint16_t pc, uint8_t offset);

	};
}
