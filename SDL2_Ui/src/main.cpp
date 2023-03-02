#include <iostream>
#include <Windows.h>

#include "Bus.h"

int main(int argc, char* argv[])
{
	bool isRunning = true;

	Bus DMNES;

	// set test reset vector
	DMNES.write(0xFFFC, 0xAA);
	DMNES.write(0xFFFD, 0x00);

	// LDA #$55
	DMNES.write(0x00AA, 0xA9);
	DMNES.write(0x00AB, 0x55);
	// LDX #$45
	DMNES.write(0x00AC, 0xA2);
	DMNES.write(0x00AD, 0x45);
	// LDY #$46
	DMNES.write(0x00AE, 0xA0);
	DMNES.write(0x00AF, 0x46);
	
	//TODO: add a power on function to insert cartrage.
	DMNES.reset();

	Byte a, b, x, y, sp;
	Word pc;
	while (isRunning)
	{
		DMNES.clock();

		DMNES.cpu.getRegisters(a, x, y, sp, pc);

		// Print Registers.
		std::cout << " A: " << (int)a << " X: " << (int)x << " Y: " << (int)y << " SP: " << (int)sp << " PC: " << pc << " PC Value: " << (int)DMNES.read(pc) << std::endl;

		Sleep(2000);
	}
}