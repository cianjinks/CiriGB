#pragma once
#include "Instruction.h"
#include "Registers.h"

namespace Ciri
{

	class CPU
	{
	private:
		InstructionSet& m_InstructionSet;
		RegisterFile m_Registers;

	public:
		CPU(InstructionSet& instructionSet) : m_InstructionSet(instructionSet) {}
	};
}
