#include <iostream>

#include "Bus.h"

int main(int argc, char* argv[])
{
	bool isRunning = true;

	Bus DMNES;

	// set test reset vector
	DMNES.write(0xFFFC, 0x00);
	DMNES.write(0xFFFD, 0xAA);
	
	//TODO: add a power on function to insert cartrage.
	DMNES.reset();

	while (isRunning)
	{
		DMNES.clock();
	}
}