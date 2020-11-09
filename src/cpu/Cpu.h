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
		RegisterFile m_Registers;
		MemoryUnit m_MemoryUnit;

	public:
		CPU();

		void Run();
	};
}
