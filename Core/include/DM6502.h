#pragma once

#include "types.h"

typedef struct {
	Byte A;
	Byte X;
	Byte Y;
	Byte SP;
	Byte flags;
	Word PC;
} DM6502Registers;

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
	void reset();	// Resets the cpu to the reset vector
	void clock();	// does one clock cycle on Cpu
	void NMI();		// does a non maskible interupt on Cpu
	void irq();		// interupts the cpu

public:
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
private: 
	DM6502Registers registers;

};