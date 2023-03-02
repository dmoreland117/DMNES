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



struct TmpValues {
	Word absAddr = 0x0000;
	Word relAddr = 0x0000;
	Byte fetched = 0x00;
	Byte opcode  = 0x00;
	int  cycles = 0;
};

enum Flags {
	C = (1 << 0),
	Z = (1 << 1),
	I = (1 << 2),
	D = (1 << 3),
	V = (1 << 5),
	N = (1 << 7),
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
	bool getFlag(Flags flag);
	bool setFlag(Flags flag, bool value);
	
	// TODO: maybe implement this a bit better.
	void getRegisters(Byte& a, Byte& x, Byte& y, Byte& sp, Word& pc);

	struct DN6502Instruction {
		const char* name;
		int			(DM6502::* opfunction)(void) = nullptr;
		int			(DM6502::* addrMode)(void) = nullptr;
		int			cycles = 0;
	};

private: 
	// addresing modes.
	int imm();	int zpy();	int abs();	int ind();
	int zp ();	int izx();	int abx();	int rel();
	int zpx();	int izy();	int aby();

	// operations.

	int XXX(); // anything not an opcode.

	// math ops.
	int ORA();	int CMP();	int DEY();	int ROL();
	int AND();	int CPX();	int INC();	int LSR();
	int EOR();	int CPY();	int INX();	int ROR();
	int ADC();	int DEC();	int INY();
	int SBC();	int DEX();	int ASL();

	// move ops.
	int LDA();	int STY();	int TSX();	int PHP();
	int STA();	int TAX();	int TXS();
	int LDX();	int TXA();	int PLA();
	int STX();	int TAY();	int PHA();
	int LDY();	int TYA();	int PLP();

	// jmp / flag ops.
	int BPL();	int BNE();	int RTS();	int CLD();	int NOP();
	int BMI();	int BEQ();	int JMP();	int SED();
	int BVC();	int BRK();	int BIT();	int CLI();
	int BCC();	int RTI();	int CLC();	int SEI();
	int BCS();	int JSR();	int SEC();	int CLV();

	inline Word incPc(Byte amount) { return m_registers.PC += amount; }
	inline int  decCycles(int amount) { return m_registers.PC -= amount; }

	void initLookupTable();

private: // members
	Bus* m_bus = nullptr;

	DM6502Registers		m_registers;
	DN6502Instruction	m_opcodeLookup[256];

	TmpValues m_helperValues;

};