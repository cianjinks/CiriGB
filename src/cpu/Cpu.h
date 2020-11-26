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
		RegisterFile m_Registers;
		MemoryUnit m_MemoryUnit;

	public:
		CPU();

		void Run();
	};
}
