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

	void InstructionSet::ExecuteInstruction(uint8_t opcode, RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)
	{
		CI_ASSERT(opcode <= 0xFF && opcode >= 0 && m_Instructions[opcode].func, "Invalid CPU Instruction Opcode Executed: {1:x}", opcode);

		DebugInstruction(m_Instructions[opcode], immediate);
		m_Instructions[opcode].func(rf, mu, immediate);
	}

	CPUInstruction InstructionSet::FetchInstruction(uint8_t opcode)
	{
		CI_ASSERT(opcode <= 0xFF && opcode >= 0 && m_Instructions[opcode].func, "Invalid CPU Instruction Opcode Fetched: {1:x}", opcode);

		return m_Instructions[opcode];
	}

	void InstructionSet::DebugInstruction(CPUInstruction& instruction, uint8_t* immediate)
	{
		if (instruction.argsLength == 0)
		{
			CI_INFO("[0x{1:x}] {0} | ARGS: null", instruction.name, instruction.opcode);
		}
		else if (instruction.argsLength == 1)
		{
			CI_INFO("[0x{2:x}] {0} | ARGS: 0x{1:x}", instruction.name, immediate[0],  instruction.opcode);
		}
		else if (instruction.argsLength == 2)
		{
			CI_INFO("[0x{3:x}] {0} | ARGS: 0x{1:x}{2:x}", instruction.name, immediate[1], immediate[0], instruction.opcode);
		}
		else 
		{
			CI_INFO("[0x{1:x}] {0} | ARGS: Unknown?", instruction.name, instruction.opcode);
		}
	}
}