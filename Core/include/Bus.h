#pragma once
#include "DM6502.h"

#define ADDR_2KB_RAM_BEGIN 0x0000
#define ADDR_2KB_RAM_END 0x07FF

#define ADDR_PPUCTRL 0x2000
#define ADDR_PPUMASK 0x2001
#define ADDR_PPUSTATUS 0x2002
// write to here onece for low byte of addres and again for the high byte of OAM data addres.
#define ADDR_OAMADDR 0x2003
// set by writing to OAMADDR.
#define ADDR_OANDATA 0x2004
#define ADDR_PPUSCROLL 0x2005
#define ADDR_PPUADDR 0x2006
#define ADDR_PPUDATA 0x2007
// sprite data is usally stored in addres $0200(in ram)
// so you would write #20 to this addres and it would transefer from $0200 - 02FF to sprite data
#define ADDR_OAMDMA 0x4014

class Bus
{
public:
	Bus();
	~Bus();

public:
	Byte read(Word a);
	Byte write(Word a, Byte d);

	void reset();
	void clock();
public:
	DM6502 cpu;
	Byte memory[2048] = {0, 0, 0};
};

