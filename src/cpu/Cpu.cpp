#include "ciripch.h"
#include "Cpu.h"

namespace Ciri
{
	CPU::CPU() 
	{
		m_InstructionSet.RegisterInstruction(CPUInstruction("NOP", (uint8_t)0x00, (uint16_t)4, (uint16_t)0, [](RegisterFile& rf, MemoryUnit& mu, uint16_t immediate){}));
		m_InstructionSet.RegisterInstruction(CPUInstruction("LD SP, nn", (uint8_t)0x31, (uint16_t)12, (uint16_t)2, [](RegisterFile& rf, MemoryUnit& mu, uint16_t immediate){ rf.SP = immediate; }));
	}

	void CPU::Run()
	{
		uint8_t opcode = m_MemoryUnit.getByte((uint32_t)m_Registers.PC);
		// Immediate Value is hardcoded for test but need to use args length
		m_InstructionSet.RunInstruction(opcode, m_Registers, m_MemoryUnit, 0xFFFE);
		m_Registers.PC++;
	}
}