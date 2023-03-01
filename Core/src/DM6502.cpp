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
}

void DM6502::clock()
{
	// get opcode
	// get addrode
	// get function
	// decrease cycles
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
	return false;
}

bool DM6502::setFlag(Flags flag)
{
	return false;
}

