#pragma once

#include "Log/Log.h"

namespace Ciri
{

	struct CPUInstruction
	{
		std::function<void()> func = nullptr;
		const char* name;
		uint16_t opcode;
		uint16_t cycles;

		CPUInstruction(const char* name, uint16_t opcode, uint16_t cycles, std::function<void()>& func) : name(name), opcode(opcode), cycles(cycles), func(func) {}
		CPUInstruction(const CPUInstruction&) {}
	};

	class InstructionSet
	{
	private:
		std::vector<CPUInstruction> m_Instructions;

	public:
		InstructionSet() : m_Instructions(0x100) {}

		void RegisterInstruction(CPUInstruction instruction);
		void RunInstruction(uint16_t opcode);
		
	};
}