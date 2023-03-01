#pragma once

#include "types.h"

class Bus;

struct DM6502Registers {
	Byte A;
	Byte X;
	Byte Y;
	Byte SP;
	Byte flags;
	Word PC;
};

struct DN6502Instruction {
	const char* name;
	int			(*opcode)()		= nullptr;
	int			(*addrMode)()	= nullptr;
	int			cycles = 0;
};

struct TmpValues {
	Word absAddr = 0x0000;
	Word relAddr = 0x00;
	Byte fetched = 0x00;
};

enum Flags {
	C = (1 << 0),
	Z = (1 << 1),
	I = (1 << 2),
	D = (1 << 3),
	V = (1 << 5),
	N = (1 << 6),
};

class DM6502 {
public:
	DM6502();
	~DM6502();

public: // input signals.
	void reset();	// Resets the cpu to the reset vector.
	void clock();	// does one clock cycle on Cpu.
	void NMI();		// does a non maskible interupt on Cpu.
	void irq();		// interupts the cpu.

	// Bus functions.
	inline void connectBus(Bus* b) { m_bus = b; }
	Byte		read(Word a);
	Byte		write(Word a, Byte d);

public: // getters and setters
	/// <summary>
	/// Gets the value of a flag on the Cpu.
	/// </summary>
	/// <param name="flag">
	///		The flag to get
	/// </param>
	/// <returns>
	///		The value of the flag.
	/// </returns>
	bool getFlag(Flags flag);
	/// <summary>
	/// Sets the value of a flag on the Cpu.
	/// </summary>
	/// <param name="flag">
	///		The flag to set
	/// </param>
	/// <returns>
	///		The value of the flag.
	/// </returns>
	bool setFlag(Flags flag);
	inline DM6502Registers getRegisters() { return m_registers; };

private: // addresing modes.
	int imm();

private: // members
	Bus* m_bus = nullptr;

	DM6502Registers		m_registers;
	DN6502Instruction	m_opcodeLookup[55];

	TmpValues m_helperValues;

};