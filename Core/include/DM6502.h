#pragma once

#include "types.h"

typedef struct {
	Byte A;
	Byte X;
	Byte Y;
	Byte flags;
	Byte SP;
	Word PC;
} DM6502Registers;

class DM6502 {
public:
	void reset();
private: 
	DM6502Registers registers;

};