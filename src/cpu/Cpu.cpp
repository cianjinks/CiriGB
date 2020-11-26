#include "ciripch.h"
#include "Cpu.h"

namespace Ciri
{
	CPU::CPU() 
	{
		// 8-bit Loads
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, n", 0x06, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = immediate[0]; }));//(r, m, a)->r.setB(a[0]));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, n", 0x0e, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.C = immediate[0]; }));//(r, m, a)->r.setC(a[0]));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, n", 0x16, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.D = immediate[0]; }));//(r, m, a)->r.setD(a[0]));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, n", 0x1e, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.E = immediate[0]; }));//(r, m, a)->r.setE(a[0]));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, n", 0x26, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.H = immediate[0]; }));//(r, m, a)->r.setH(a[0]));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, n", 0x2e, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.L = immediate[0]; }));//(r, m, a)->r.setL(a[0]));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, A", 0x7f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.A; }));//(r, m, a)->r.setA(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, B", 0x78, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.B; }));//(r, m, a)->r.setA(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, C", 0x79, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.C; }));//(r, m, a)->r.setA(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, D", 0x7A, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.D; }));//(r, m, a)->r.setA(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, E", 0x7B, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.E; }));//(r, m, a)->r.setA(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, H", 0x7C, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.H; }));//(r, m, a)->r.setA(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, L", 0x7D, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = rf.L; }));//(r, m, a)->r.setA(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (HL)", 0x7E, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, L", 0x45, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.L; }));//(r, m, a)->r.setB(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, B", 0x40, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.B; }));//(r, m, a)->r.setB(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, C", 0x41, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.C; }));//(r, m, a)->r.setB(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, D", 0x42, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.D; }));//(r, m, a)->r.setB(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, E", 0x43, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.E; }));//(r, m, a)->r.setB(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, H", 0x44, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.B = rf.H; }));//(r, m, a)->r.setB(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, (HL)", 0x46, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.B = mu.getByte(rf.getHL()); })); //(r, m, a)->r.setB(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, B", 0x48, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.B; }));//(r, m, a)->r.setC(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, C", 0x49, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.C; }));//(r, m, a)->r.setC(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, D", 0x4a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.D; }));//(r, m, a)->r.setC(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, E", 0x4b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.E; }));//(r, m, a)->r.setC(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, H", 0x4c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.H; }));//(r, m, a)->r.setC(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, L", 0x4d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.C = rf.L; }));//(r, m, a)->r.setC(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, (HL)", 0x4e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.C = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setC(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, B", 0x50, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.B; }));//(r, m, a)->r.setD(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, C", 0x51, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.C; }));//(r, m, a)->r.setD(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, D", 0x52, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.D; }));//(r, m, a)->r.setD(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, E", 0x53, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.E; }));//(r, m, a)->r.setD(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, H", 0x54, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.H; }));//(r, m, a)->r.setD(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, L", 0x55, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.D = rf.L; }));//(r, m, a)->r.setD(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, (HL)", 0x56, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.D = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setD(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, B", 0x58, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.B; }));//(r, m, a)->r.setE(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, C", 0x59, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.C; }));//(r, m, a)->r.setE(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, D", 0x5a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.D; }));//(r, m, a)->r.setE(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, E", 0x5b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.E; }));//(r, m, a)->r.setE(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, H", 0x5c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.H; }));//(r, m, a)->r.setE(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, L", 0x5d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.E = rf.L; }));//(r, m, a)->r.setE(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, (HL)", 0x5e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.E = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setE(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, B", 0x60, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.B; }));//(r, m, a)->r.setH(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, C", 0x61, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.C; }));//(r, m, a)->r.setH(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, D", 0x62, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.D; }));//(r, m, a)->r.setH(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, E", 0x63, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.E; }));//(r, m, a)->r.setH(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, H", 0x64, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.H; }));//(r, m, a)->r.setH(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, L", 0x65, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.H = rf.L; }));//(r, m, a)->r.setH(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, (HL)", 0x66, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.H = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setH(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, B", 0x68, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.B; }));//(r, m, a)->r.setL(r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, C", 0x69, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.C; }));//(r, m, a)->r.setL(r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, D", 0x6a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.D; }));//(r, m, a)->r.setL(r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, E", 0x6b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.E; }));//(r, m, a)->r.setL(r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, H", 0x6c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.H; }));//(r, m, a)->r.setL(r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, L", 0x6d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.L = rf.L; }));//(r, m, a)->r.setL(r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, (HL)", 0x6e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.L = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setL(m.getByte(r.getHL())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), B", 0x70, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.B); }));//(r, m, a)->m.setByte(r.getHL(), r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), C", 0x71, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.C); }));//(r, m, a)->m.setByte(r.getHL(), r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), D", 0x72, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.D); }));//(r, m, a)->m.setByte(r.getHL(), r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), E", 0x73, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.E); }));//(r, m, a)->m.setByte(r.getHL(), r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), H", 0x74, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.H); }));//(r, m, a)->m.setByte(r.getHL(), r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), L", 0x75, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.L); }));//(r, m, a)->m.setByte(r.getHL(), r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), n", 0x36, 12, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.getHL(), (uint16_t)immediate[0]); }));//(r, m, a)->m.setByte(r.getHL(), a[0]));

        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, A", 0x7f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getA()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, B", 0x78, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getB()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, C", 0x79, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getC()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, D", 0x7a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getD()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, E", 0x7b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getE()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, H", 0x7c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getH()));
        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, L", 0x7d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(r.getL()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (BC)", 0x0a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { rf.A = mu.getByte(rf.getBC()); }));//(r, m, a)->r.setA(m.getByte(r.getBC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (DE)", 0x1a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { rf.A = mu.getByte(rf.getDE()); }));//(r, m, a)->r.setA(m.getByte(r.getDE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (HL)", 0x7e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { rf.A = mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(m.getByte(r.getHL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (nn)", 0xfa, 16, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = mu.getByte(CI_TO16(immediate[0], immediate[1])); }));//(r, m, a)->r.setA(m.getByte(toWord(a))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, #", 0x3e, 16, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)    { rf.A = immediate[0]; }));//(r, m, a)->r.setA(a[0]));

        //m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, A", 0x7f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     {}));//(r, m, a)->r.setA(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD B, A", 0x47, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.B = rf.A; }));//(r, m, a)->r.setB(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD C, A", 0x4f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.C = rf.A; }));//(r, m, a)->r.setC(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD D, A", 0x57, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.D = rf.A; }));//(r, m, a)->r.setD(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD E, A", 0x5f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.E = rf.A; }));//(r, m, a)->r.setE(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD H, A", 0x67, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.H = rf.A; }));//(r, m, a)->r.setH(r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD L, A", 0x6f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)     { rf.L = rf.A; }));//(r, m, a)->r.setL(r.getA()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (BC), A", 0x02, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getBC(), (uint16_t)rf.A); }));//(r, m, a)->m.setByte(r.getBC(), r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (DE), A", 0x12, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getDE(), (uint16_t)rf.A); }));//(r, m, a)->m.setByte(r.getDE(), r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HL), A", 0x77, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)  { mu.setByte(rf.getHL(), (uint16_t)rf.A); }));//(r, m, a)->m.setByte(r.getHL(), r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (nn), A", 0xea, 16, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(CI_TO16(immediate[0], immediate[1]), rf.A); }));//(r, m, a)->m.setByte(toWord(a), r.getA()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (C)", 0xf2, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)   { rf.A = mu.getByte((uint16_t)rf.C); }));//(r, m, a)->r.setA(m.getByte(0xff00 + r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (C), A", 0xe2, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)   { mu.setByte((uint16_t)rf.C, rf.A); }));//(r, m, a)->m.setByte(0xff00 + r.getC(), r.getA()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (HLD)", 0x3a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = mu.getByte(rf.decrementHL()); }));//(r, m, a)->r.setA(m.getByte(r.decrementHL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HLD), A", 0x32, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.decrementHL(), rf.A); }));//(r, m, a)->m.setByte(r.decrementHL(), r.getA()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD A, (HLI)", 0x2a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = mu.getByte(rf.incrementHL()); }));//(r, m, a)->r.setA(m.getByte(r.incrementHL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (HLI), A", 0x22, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.incrementHL(), rf.A); }));//(r, m, a)->m.setByte(r.incrementHL(), r.getA()));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LDH (n), A", 0xe0, 12, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(0xFF00 + immediate[0], rf.A); }));//(r, m, a)->m.setByte(0xff00 + a[0], r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LDH A, (n)", 0xf0, 12, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = mu.getByte(0xFF00 + immediate[0]); }));//(r, m, a)->r.setA(m.getByte(0xff00 + a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("LD BC, nn", 0x01, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setBC(CI_TO16(immediate[0], immediate[1])); }));//(r, m, a)->r.setBC(toWord(a)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD DE, nn", 0x11, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setDE(CI_TO16(immediate[0], immediate[1])); }));//(r, m, a)->r.setDE(toWord(a)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD HL, nn", 0x21, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(CI_TO16(immediate[0], immediate[1])); }));//(r, m, a)->r.setHL(toWord(a)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD SP, nn", 0x31, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = CI_TO16(immediate[0], immediate[1]);   }));//(r, m, a)->r.setSP(toWord(a)));

        // 16-bit loads
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD SP, HL", 0xf9, 8, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.getHL(); }));//(r, m, a)->r.setSP(r.getHL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LDHL SP, n", 0xf8, 12, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.SP + (int)immediate[0]); }));//(r, m, a)->r.setHL(addSignedByteToWord(r.getFlags(), r.getSP(), a[0])));
        m_InstructionSet.RegisterInstruction(CPUInstruction("LD (nn), SP", 0x08, 20, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(CI_TO16(immediate[0], immediate[1]), rf.SP); }));//(r, m, a) -> { m.setByte(toWord(a), getLSB(r.getSP())); m.setByte((toWord(a) + 1) & 0xffff, getMSB(r.getSP())); });

        m_InstructionSet.RegisterInstruction(CPUInstruction("PUSH AF", 0xf5, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP - 2; mu.setByte(rf.SP, rf.getAF()); }));//(r, m, a)->push(r, m, r.getAF()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("PUSH BC", 0xc5, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP - 2; mu.setByte(rf.SP, rf.getBC()); }));//(r, m, a)->push(r, m, r.getBC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("PUSH DE", 0xd5, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP - 2; mu.setByte(rf.SP, rf.getDE()); }));//(r, m, a)->push(r, m, r.getDE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("PUSH HL", 0xe5, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP - 2; mu.setByte(rf.SP, rf.getHL()); }));//(r, m, a)->push(r, m, r.getHL()));

        // TODO: Flags are affected here apparently
        m_InstructionSet.RegisterInstruction(CPUInstruction("POP BC", 0xc1, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setBC(mu.getByte(rf.SP)); rf.SP = rf.SP + 2; }));//(r, m, a)->r.setBC(pop(r, m)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("POP DE", 0xd1, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setDE(mu.getByte(rf.SP)); rf.SP = rf.SP + 2; }));//(r, m, a)->r.setDE(pop(r, m)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("POP AF", 0xf1, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setAF(mu.getByte(rf.SP)); rf.SP = rf.SP + 2; }));//(r, m, a)->r.setAF(pop(r, m)));
        m_InstructionSet.RegisterInstruction(CPUInstruction("POP HL", 0xe1, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(mu.getByte(rf.SP)); rf.SP = rf.SP + 2; }));//(r, m, a)->r.setHL(pop(r, m)));

        // TODO: Flags for all instructions past here I believe
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, A", 0x87, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.A; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, B", 0x80, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.B; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, C", 0x81, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.C; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, D", 0x82, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.D; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, E", 0x83, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.E; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, H", 0x84, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.H; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, L", 0x85, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.L; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, (HL)", 0x86, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD A, #", 0xc6, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + immediate[0]; }));//(r, m, a)->r.setA(addBytes(r.getFlags(), r.getA(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, A", 0x8f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.A; }));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, B", 0x88, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.B;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, C", 0x89, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.C;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, D", 0x8a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.D;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, E", 0x8b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.E;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, H", 0x8c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.H;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, L", 0x8d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + rf.L;}));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, (HL)", 0x8e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADC A, #", 0xce, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A + immediate[0]; }));//(r, m, a)->r.setA(addBytesAndCarry(r.getFlags(), r.getA(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, A", 0x97, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.A; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, B", 0x90, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.B; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, C", 0x91, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.C; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, D", 0x92, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.D; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, E", 0x93, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.E; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, H", 0x94, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.H; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, L", 0x95, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.L; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, (HL)", 0x96, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SUB A, #", 0xd6, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - immediate[0]; }));//(r, m, a)->r.setA(subBytes(r.getFlags(), r.getA(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, A", 0x9f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.A; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, B", 0x98, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.B; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, C", 0x99, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.C; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, D", 0x9a, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.D; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, E", 0x9b, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.E; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, H", 0x9c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.H; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, L", 0x9d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - rf.L; }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, (HL)", 0x9e, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(subBytesWithCarry(r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("SBC A, #", 0x9e, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A - immediate[0]; }));

        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, A", 0xa7, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.A; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, B", 0xa0, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.B; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, C", 0xa1, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.C; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, D", 0xa2, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.D; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, E", 0xa3, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.E; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, H", 0xa4, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.H; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, L", 0xa5, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & rf.L; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, (HL)", 0xa6, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("AND A, #", 0xe6, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A & immediate[0]; }));//(r, m, a)->r.setA(and (r.getFlags(), r.getA(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, A", 0xb7, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.A; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, B", 0xb0, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.B; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, C", 0xb1, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.C; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, D", 0xb2, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.D; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, E", 0xb3, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.E; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, H", 0xb4, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.H; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, L", 0xb5, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | rf.L; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, (HL)", 0xb6, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("OR A, #", 0xf6, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A | immediate[0]; }));//(r, m, a)->r.setA(or (r.getFlags(), r.getA(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, A", 0xaf, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.A; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, B", 0xa8, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.B; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, C", 0xa9, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.C; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, D", 0xaa, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.D; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, E", 0xab, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.E; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, H", 0xac, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.H; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, L", 0xad, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ rf.L; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, (HL)", 0xae, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ mu.getByte(rf.getHL()); }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), m.getByte(r.getHL()))));
        m_InstructionSet.RegisterInstruction(CPUInstruction("XOR A, #", 0xee, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = rf.A ^ immediate[0]; }));//(r, m, a)->r.setA(xor (r.getFlags(), r.getA(), a[0])));

        // TODO
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, A", 0xbf, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getA()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, B", 0xb8, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getB()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, C", 0xb9, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getC()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, D", 0xba, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getD()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, E", 0xbb, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getE()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, H", 0xbc, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getH()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, L", 0xbd, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), r.getL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, (HL)", 0xbe, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), m.getByte(r.getHL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("CP A, #", 0xfe, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->subBytes(r.getFlags(), r.getA(), a[0]));

        m_InstructionSet.RegisterInstruction(CPUInstruction("INC A", 0x3c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A++; }));//(r, m, a)->r.setA(inc(r.getFlags(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC B", 0x04, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.B++; }));//(r, m, a)->r.setB(inc(r.getFlags(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC C", 0x0c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.C++; }));//(r, m, a)->r.setC(inc(r.getFlags(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC D", 0x14, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.D++; }));//(r, m, a)->r.setD(inc(r.getFlags(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC E", 0x1c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.E++; }));//(r, m, a)->r.setE(inc(r.getFlags(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC H", 0x24, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.H++; }));//(r, m, a)->r.setH(inc(r.getFlags(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC L", 0x2c, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.L++; }));//(r, m, a)->r.setL(inc(r.getFlags(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC (HL)", 0x34, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.getHL(), mu.getByte(rf.getHL()) + 1); }));//(r, m, a)->m.setByte(r.getHL(), inc(r.getFlags(), m.getByte(r.getHL()))));

        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC A", 0x3d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A--; }));//(r, m, a)->r.setA(dec(r.getFlags(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC B", 0x05, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.B--; }));//(r, m, a)->r.setB(dec(r.getFlags(), r.getB())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC C", 0x0d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.C--; }));//(r, m, a)->r.setC(dec(r.getFlags(), r.getC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC D", 0x15, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.D--; }));//(r, m, a)->r.setD(dec(r.getFlags(), r.getD())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC E", 0x1d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.E--; }));//(r, m, a)->r.setE(dec(r.getFlags(), r.getE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC H", 0x25, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.H--; }));//(r, m, a)->r.setH(dec(r.getFlags(), r.getH())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC L", 0x2d, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.L--; }));//(r, m, a)->r.setL(dec(r.getFlags(), r.getL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC (HL)", 0x35, 12, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.getHL(), mu.getByte(rf.getHL()) - 1); }));//(r, m, a)->m.setByte(r.getHL(), dec(r.getFlags(), m.getByte(r.getHL()))));

        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD HL, BC", 0x09, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() + rf.getBC()); }));//(r, m, a)->r.setHL(addWords(r.getFlags(), r.getHL(), r.getBC())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD HL, DE", 0x19, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() + rf.getDE()); }));//(r, m, a)->r.setHL(addWords(r.getFlags(), r.getHL(), r.getDE())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD HL, HL", 0x29, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() + rf.getHL()); }));//(r, m, a)->r.setHL(addWords(r.getFlags(), r.getHL(), r.getHL())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD HL, SP", 0x39, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() + rf.SP); }));//(r, m, a)->r.setHL(addWords(r.getFlags(), r.getHL(), r.getSP())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("ADD SP, #", 0xe8, 16, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP + (int)immediate[0]; }));//(r, m, a)->r.setSP(addSignedByteToWord(r.getFlags(), r.getSP(), a[0])));

        m_InstructionSet.RegisterInstruction(CPUInstruction("INC BC", 0x03, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setBC(rf.getBC() + 1); }));//(r, m, a)->r.setBC((r.getBC() + 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC DE", 0x13, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setDE(rf.getDE() + 1); }));//(r, m, a)->r.setDE((r.getDE() + 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC HL", 0x23, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() + 1); }));//(r, m, a)->r.setHL((r.getHL() + 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("INC SP", 0x33, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.SP = rf.SP + 1; }));//(r, m, a)->r.setSP((r.getSP() + 1) & 0xffff));

        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC BC", 0x0b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setBC(rf.getBC() - 1); }));//(r, m, a)->r.setBC((r.getBC() - 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC DE", 0x1b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setDE(rf.getDE() - 1); }));//(r, m, a)->r.setDE((r.getDE() - 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC HL", 0x2b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.setHL(rf.getHL() - 1); }));//(r, m, a)->r.setHL((r.getHL() - 1) & 0xffff));
        m_InstructionSet.RegisterInstruction(CPUInstruction("DEC SP", 0x3b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {rf.SP = rf.SP - 1; }));//(r, m, a)->r.setSP((r.getSP() - 1) & 0xffff));

        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP A", 0x37, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.A = (((rf.A & 0x0F) << 4) | ((rf.A & 0xF0) >> 4)); }));//(r, m, a)->r.setA(swap(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP B", 0x30, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.B = (((rf.B & 0x0F) << 4) | ((rf.B & 0xF0) >> 4)); }));//(r, m, a)->r.setB(swap(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP C", 0x31, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.C = (((rf.C & 0x0F) << 4) | ((rf.C & 0xF0) >> 4)); }));//(r, m, a)->r.setC(swap(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP D", 0x32, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.D = (((rf.D & 0x0F) << 4) | ((rf.D & 0xF0) >> 4)); }));//(r, m, a)->r.setD(swap(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP E", 0x33, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.E = (((rf.E & 0x0F) << 4) | ((rf.E & 0xF0) >> 4)); }));//(r, m, a)->r.setE(swap(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP H", 0x34, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.H = (((rf.H & 0x0F) << 4) | ((rf.H & 0xF0) >> 4)); }));//(r, m, a)->r.setH(swap(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP L", 0x35, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { rf.L = (((rf.L & 0x0F) << 4) | ((rf.L & 0xF0) >> 4)); }));//(r, m, a)->r.setL(swap(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SWAP (HL)", 0x36, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) { mu.setByte(rf.getHL(), (((mu.getByte(rf.getHL()) & 0x0F) << 4) | ((mu.getByte(rf.getHL()) & 0xF0) >> 4))); }));//(r, m, a)->m.setByte(r.getHL(), swap(r.getFlags(), m.getByte(r.getHL()))));

        //regCmd(commands, 0x27, 4, 0, "DAA", (r, m, a) -> {
        //    int result = r.getA();
        //    if ((result & 0x0f) > 9 || r.getFlags().isH()) {
        //        result += 0x06;
        //    }
        //    if ((result & 0xf0) > 0x90 || r.getFlags().isC()) {
        //        result += 0x60;
        //        r.getFlags().setC(true);
        //    }
        //    result &= 0xff;
        //    r.getFlags().setZ(result == 0);
        //    r.getFlags().setH(false);
        //    r.setA(result);
        //});
        //
        //regCmd(commands, 0x2f, 4, 0, "CPL", (r, m, a) -> {
        //    r.getFlags().setN(true);
        //    r.getFlags().setH(true);
        //    r.setA((~r.getA()) & 0xff);
        //});
        //
        //regCmd(commands, 0x3f, 4, 0, "CCF", (r, m, a) -> {
        //    r.getFlags().setN(false);
        //    r.getFlags().setH(false);
        //    r.getFlags().setC(!r.getFlags().isC());
        //});
        //
        //regCmd(commands, 0x37, 4, 0, "SCF", (r, m, a) -> {
        //    r.getFlags().setN(false);
        //    r.getFlags().setH(false);
        //    r.getFlags().setC(true);
        //});

        m_InstructionSet.RegisterInstruction(CPUInstruction("NOP", 0x00, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {});
        m_InstructionSet.RegisterInstruction(CPUInstruction("HALT", 0x76, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {/* TODO */});
        m_InstructionSet.RegisterInstruction(CPUInstruction("STOP", 0x10, 4, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {/* TODO */});
        m_InstructionSet.RegisterInstruction(CPUInstruction("DI", 0xf3, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {/* TODO */});
        m_InstructionSet.RegisterInstruction(CPUInstruction("EI", 0xfb, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {/* TODO */});

        m_InstructionSet.RegisterInstruction(CPUInstruction("RLCA", 0x07, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateLeft(r.getFlags(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RLA", 0x17, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateLeftThroughCarry(r.getFlags(), r.getA())));

        m_InstructionSet.RegisterInstruction(CPUInstruction("RRCA", 0x0f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateRight(r.getFlags(), r.getA())));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RRA", 0x1f, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateRightThroughCarry(r.getFlags(), r.getA())));

        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC A", 0x07, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateLeft(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC B", 0x00, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(rotateLeft(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC C", 0x01, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(rotateLeft(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC D", 0x02, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(rotateLeft(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC E", 0x03, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(rotateLeft(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC H", 0x04, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(rotateLeft(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC L", 0x05, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(rotateLeft(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RLC (HL)", 0x06, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), rotateLeft(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL A", 0x17, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateLeftThroughCarry(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL B", 0x10, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(rotateLeftThroughCarry(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL C", 0x11, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(rotateLeftThroughCarry(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL D", 0x12, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(rotateLeftThroughCarry(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL E", 0x13, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(rotateLeftThroughCarry(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL H", 0x14, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(rotateLeftThroughCarry(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL L", 0x15, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(rotateLeftThroughCarry(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RL (HL)", 0x16, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), rotateLeftThroughCarry(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC A", 0x0f, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateRight(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC B", 0x08, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(rotateRight(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC C", 0x09, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(rotateRight(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC D", 0x0a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(rotateRight(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC E", 0x0b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(rotateRight(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC H", 0x0c, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(rotateRight(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC L", 0x0d, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(rotateRight(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RRC (HL)", 0x0e, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), rotateRight(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR A", 0x1f, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(rotateRightThroughCarry(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR B", 0x18, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(rotateRightThroughCarry(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR C", 0x19, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(rotateRightThroughCarry(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR D", 0x1a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(rotateRightThroughCarry(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR E", 0x1b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(rotateRightThroughCarry(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR H", 0x1c, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(rotateRightThroughCarry(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR L", 0x1d, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(rotateRightThroughCarry(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("RR (HL)", 0x1e, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), rotateRightThroughCarry(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA A", 0x27, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(shiftLeft(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA B", 0x20, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(shiftLeft(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA C", 0x21, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(shiftLeft(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA D", 0x22, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(shiftLeft(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA E", 0x23, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(shiftLeft(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA H", 0x24, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(shiftLeft(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA L", 0x25, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(shiftLeft(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SLA (HL)", 0x26, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), shiftLeft(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA A", 0x2f, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(shiftRightArtithmetic(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA B", 0x28, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(shiftRightArtithmetic(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA C", 0x29, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(shiftRightArtithmetic(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA D", 0x2a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(shiftRightArtithmetic(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA E", 0x2b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(shiftRightArtithmetic(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA H", 0x2c, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(shiftRightArtithmetic(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA L", 0x2d, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(shiftRightArtithmetic(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRA (HL)", 0x2e, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), shiftRightArtithmetic(r.getFlags(), m.getByte(r.getHL()))));
          
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL A", 0x3f, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(shiftRightLogical(r.getFlags(), r.getA())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL B", 0x38, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setB(shiftRightLogical(r.getFlags(), r.getB())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL C", 0x39, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setC(shiftRightLogical(r.getFlags(), r.getC())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL D", 0x3a, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setD(shiftRightLogical(r.getFlags(), r.getD())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL E", 0x3b, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setE(shiftRightLogical(r.getFlags(), r.getE())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL H", 0x3c, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setH(shiftRightLogical(r.getFlags(), r.getH())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL L", 0x3d, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setL(shiftRightLogical(r.getFlags(), r.getL())));
        m_CBInstructionSet.RegisterInstruction(CPUInstruction("SRL (HL)", 0x3e, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), shiftRightLogical(r.getFlags(), m.getByte(r.getHL()))));

        for (int i = 0; i < 8; i++) {
            int bit = i;
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", A")).c_str(), 0x47 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getA(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", B")).c_str(), 0x40 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getB(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", C")).c_str(), 0x41 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getC(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", D")).c_str(), 0x42 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getD(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", E")).c_str(), 0x43 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getE(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", H")).c_str(), 0x44 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getH(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", L")).c_str(), 0x45 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), r.getL(), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("BIT ") + std::to_string(bit) + std::string(", (HL)")).c_str(), 0x46 + 0x08 * bit, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->bit(r.getFlags(), m.getByte(r.getHL()), bit));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", A")).c_str(), 0xc7 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getA(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", B")).c_str(), 0xc0 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getB(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", C")).c_str(), 0xc1 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getC(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", D")).c_str(), 0xc2 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getD(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", E")).c_str(), 0xc3 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getE(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", H")).c_str(), 0xc4 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getH(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", L")).c_str(), 0xc5 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(setBit(r.getL(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("SET ") + std::to_string(bit) + std::string(", (HL)")).c_str(), 0xc6 + 0x08 * bit, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), setBit(m.getByte(r.getHL()), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", A")).c_str(), 0x87 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getA(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", B")).c_str(), 0x80 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getB(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", C")).c_str(), 0x81 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getC(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", D")).c_str(), 0x82 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getD(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", E")).c_str(), 0x83 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getE(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", H")).c_str(), 0x84 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getH(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", L")).c_str(), 0x85 + 0x08 * bit, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setA(clearBit(r.getL(), bit)));
            m_CBInstructionSet.RegisterInstruction(CPUInstruction((std::string("RES ") + std::to_string(bit) + std::string(", (HL)")).c_str(), 0x86 + 0x08 * bit, 16, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->m.setByte(r.getHL(), clearBit(m.getByte(r.getHL()), bit)));
        }

        m_InstructionSet.RegisterInstruction(CPUInstruction("JMP nn", 0xc3, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setPC(toWord(a)));

        m_InstructionSet.RegisterInstruction(CPUInstruction("JP NZ, nn", 0xc2, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isZ()) r.setPC(toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JP Z, nn", 0xca, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isZ())  r.setPC(toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JP NC, nn", 0xd2, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isC()) r.setPC(toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JP C, nn", 0xda, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isC())  r.setPC(toWord(a)); });

        m_InstructionSet.RegisterInstruction(CPUInstruction("JP (HL)", 0xe9, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.setPC(r.getHL()));
        m_InstructionSet.RegisterInstruction(CPUInstruction("JR n", 0x18, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->r.addToPC(a[0]));

        m_InstructionSet.RegisterInstruction(CPUInstruction("JR NZ, n", 0x20, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isZ()) r.addToPC(a[0]); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JR Z, n", 0x28, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isZ())  r.addToPC(a[0]); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JR NC, n", 0x30, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isC()) r.addToPC(a[0]); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("JR C, n", 0x38, 8, 1, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isC())  r.addToPC(a[0]); });

        m_InstructionSet.RegisterInstruction(CPUInstruction("CALL nn", 0xcd, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->call(r, m, toWord(a)));

        m_InstructionSet.RegisterInstruction(CPUInstruction("CALL NZ, n", 0xc4, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isZ()) call(r, m, toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("CALL Z, n", 0xcc, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isZ())  call(r, m, toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("CALL NC, n", 0xd4, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isC()) call(r, m, toWord(a)); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("CALL C, n", 0xdc, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isC())  call(r, m, toWord(a)); });

        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 00H", 0xc7, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x00));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 08H", 0xcf, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x08));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 10H", 0xd7, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x10));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 18H", 0xdf, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x18));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 20H", 0xe7, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x20));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 28H", 0xef, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x28));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 30H", 0xf7, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x30));
        m_InstructionSet.RegisterInstruction(CPUInstruction("RST 38H", 0xff, 32, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->reset(r, m, 0x38));

        m_InstructionSet.RegisterInstruction(CPUInstruction("RET", 0xc9, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a)->ret(r, m));

        m_InstructionSet.RegisterInstruction(CPUInstruction("RET NZ", 0xc0, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isZ()) ret(r, m); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("RET Z", 0xc8, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isZ())  ret(r, m); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("RET NC", 0xd0, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (!r.getFlags().isC()) ret(r, m); });
        m_InstructionSet.RegisterInstruction(CPUInstruction("RET C", 0xd8, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> { if (r.getFlags().isC())  ret(r, m); });

        m_InstructionSet.RegisterInstruction(CPUInstruction("RETI", 0xd9, 8, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate) {}));//(r, m, a) -> {ret(r, m); /* TODO enabled interrupts */ });

		// Practice
		//m_InstructionSet.RegisterInstruction(CPUInstruction("NOP", 0x00, 4, 0, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate){}));
		//m_InstructionSet.RegisterInstruction(CPUInstruction("LD SP, nn", 0x31, 12, 2, [](RegisterFile& rf, MemoryUnit& mu, uint8_t* immediate)
		//{ 
		//	rf.SP = (uint16_t)immediate[0] | ((uint16_t)immediate[1]) << 8;
		//}));
	}

	void CPU::Run()
	{
        CPUInstruction instruction;
		uint8_t opcode = m_MemoryUnit.getByte((uint32_t)m_Registers.PC++);
        if (opcode == 0xCB)
        {
            opcode = m_MemoryUnit.getByte((uint32_t)m_Registers.PC++);
            instruction = m_CBInstructionSet.FetchInstruction(opcode);

            uint8_t args[2];
            for (int arg = 0; arg < instruction.argsLength; arg++)
            {
                args[arg] = m_MemoryUnit.getByte((uint32_t)m_Registers.PC++);
            }

            m_CBInstructionSet.ExecuteInstruction(opcode, m_Registers, m_MemoryUnit, args);
        }
        else if (opcode == 0x00)
        {
            return;
        }
        else
        {
            instruction = m_InstructionSet.FetchInstruction(opcode);

            uint8_t args[2];
            for (int arg = 0; arg < instruction.argsLength; arg++)
            {
                args[arg] = m_MemoryUnit.getByte((uint32_t)m_Registers.PC++);
            }

            m_InstructionSet.ExecuteInstruction(opcode, m_Registers, m_MemoryUnit, args);
        }
	}
}