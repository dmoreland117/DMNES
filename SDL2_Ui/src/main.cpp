#include <iostream>

#include "Bus.h"

int main(int argc, char* argv[])
{
	bool isRunning = true;

	Bus DMNES;

	//TODO: add a power on function to insert cartrage.
	DMNES.reset();

	while (isRunning)
	{
		DMNES.clock();
	}
}