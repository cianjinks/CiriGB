#pragma once
#include "Register.h"
#include "Memory/MemoryUnit.h"
#include "Instruction.h"

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
