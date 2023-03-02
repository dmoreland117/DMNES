#include "DM6502.h"
#include "Bus.h"

DM6502::DM6502()
{
	//reset();
}

DM6502::~DM6502()
{
	// do nothing.
}

void DM6502::reset()
{
	// set registers.
	m_registers.A = 0x00;
	m_registers.X = 0x00;
	m_registers.Y = 0x00;
	m_registers.SP = 0x00;
	m_registers.flags = 0x00;
	// i dont know if i need to set this since im doing it again while setting reset vector.
	m_registers.PC = 0x0000;

	// clear RAM.
	//for (Word i = 0; i < 65535; i++)
	//{
	//	write(i, 0x00);
	//}

	// set reset vector.
	Byte pcHi, pcLo;

	pcLo = read(0xFFFC);
	pcHi = read(0xFFFD);
	m_registers.PC = (pcHi << 8) | pcLo;

	// reset the helper values.
	m_helperValues = { 0, 0, 0 };

	initLookupTable();
	
}

void DM6502::clock()
{
	// get opcode
	if (m_helperValues.cycles == 0) {
		
		m_helperValues.opcode = read(m_registers.PC);
		m_helperValues.cycles = m_opcodeLookup[m_helperValues.opcode].cycles;

		// get addrode
		int cycles1 = (this->*m_opcodeLookup[m_helperValues.opcode].addrMode)();
		// get function
		int cycles2 = (this->*m_opcodeLookup[m_helperValues.opcode].opfunction)();
		// decrease cycles

		if ((cycles1 + cycles2) == 2) m_helperValues.cycles++;
	}
	m_helperValues.cycles--;
}

void DM6502::NMI()
{
}

void DM6502::irq()
{
}

inline Byte DM6502::read(Word a)
{
	return m_bus->read(a);

}

inline Byte DM6502::write(Word a, Byte d)
{
	return m_bus->write(a, d);
}

bool DM6502::getFlag(Flags flag)
{
	return ((m_registers.flags & flag) > 0) ? 1 : 0;
}

bool DM6502::setFlag(Flags flag, bool value)
{
	if(value)
	{
		m_registers.flags |= flag;
	}
	else 
	{
		m_registers.flags &= ~flag;
	}
	// TODO: return value of flag.
	return true;
}

void DM6502::getRegisters(Byte& a, Byte& x, Byte& y, Byte& sp, Word& pc)
{
	a =  m_registers.A;
	x =  m_registers.X;
	y =  m_registers.Y;
	sp = m_registers.SP;
	pc = m_registers.PC;
}

int DM6502::XXX() 
{
	return 0;
}

int DM6502::imm()
{
	m_helperValues.absAddr = m_registers.PC + 1;
	incPc(1);
	return 0;
}

int DM6502::LDA()
{
	m_registers.A = read(m_helperValues.absAddr);

	// set flags
	(m_registers.A == 0x00) ? setFlag(Z, true) : setFlag(Z, false);
	setFlag(N, m_registers.A & 0b10000000);

	incPc(1);

	return 1;
}

int DM6502::LDX()
{
	m_registers.X = read(m_helperValues.absAddr);

	// set flags
	(m_registers.X == 0x00) ? setFlag(Z, true) : setFlag(Z, false);
	setFlag(N, m_registers.X & 0b10000000);

	incPc(1);

	return 1;
}

int DM6502::LDY()
{
	m_registers.Y = read(m_helperValues.absAddr);

	// set flags
	(m_registers.Y == 0x00) ? setFlag(Z, true) : setFlag(Z, false);
	setFlag(N, m_registers.Y & 0b10000000);

	incPc(1);

	return 1;
}

void DM6502::initLookupTable()
{
	m_opcodeLookup[0x00] = {
		"XXX", &DM6502::XXX, &DM6502::XXX, 2
	};
	m_opcodeLookup[0xA9] = {
		"LDA", &DM6502::LDA, &DM6502::imm, 2
	};
	m_opcodeLookup[0xA2] = {
		"LDX", &DM6502::LDX, &DM6502::imm, 2
	};
	m_opcodeLookup[0xA0] = {
		"LDY", &DM6502::LDY, &DM6502::imm, 2
	};
}
