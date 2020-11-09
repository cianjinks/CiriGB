#include "ciripch.h"
#include "Instruction.h"

namespace Ciri
{
	void InstructionSet::RegisterInstruction(CPUInstruction instruction)
	{
		if (instruction.opcode <= 0xFF && instruction.opcode >= 0)
		{
			m_Instructions[instruction.opcode] = instruction;
		}
		else
		{
			CI_ERROR("Invalid CPU Instruction Opcode Registered: {1:x}", instruction.opcode);
		}
	}

	void InstructionSet::RunInstruction(uint16_t opcode)
	{
		CI_ASSERT(opcode <= 0xFF && opcode >= 0 && m_Instructions[opcode].func, "Invalid CPU Instruction Opcode Executed: {1:x}", opcode);

		m_Instructions[opcode].func();
	}
}