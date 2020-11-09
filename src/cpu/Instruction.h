#pragma once
#include "Log/Log.h"
#include "Register.h"
#include "Memory/MemoryUnit.h"

namespace Ciri
{
	struct CPUInstruction
	{
		std::function<void(RegisterFile&, MemoryUnit&, uint16_t)> func = nullptr;
		const char* name = "";
		uint8_t opcode = 0;
		uint16_t cycles = 0;
		uint16_t argsLength = 0;

		CPUInstruction() {}
		CPUInstruction(const char* name, uint8_t opcode, uint16_t cycles, uint16_t argsLength, std::function<void(RegisterFile&, MemoryUnit&, uint16_t)> func) 
			: name(name), opcode(opcode), cycles(cycles), argsLength(argsLength), func(func) {}
	};

	class InstructionSet
	{
	private:
		std::vector<CPUInstruction> m_Instructions;

	public:
		InstructionSet() : m_Instructions(0x100) {}

		void RegisterInstruction(CPUInstruction instruction);
		void RunInstruction(uint8_t opcode, RegisterFile& rf, MemoryUnit& mu, uint16_t immediate);
		
	};
}