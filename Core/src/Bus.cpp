#include "Bus.h"

#include <iostream>

Bus::Bus()
{
    // Connect devices to the bus.
    cpu.connectBus(this);

    //TODO
    //ppu.connectBus(this);
    //apu.connectBus(this);
}

Bus::~Bus()
{
}

Byte Bus::read(Word a)
{
    if (a >= 0x0000 && a <= 0xFFFF) {
        return memory[a];
    }
    return 0x00;
}

Byte Bus::write(Word a, Byte d)
{
    if (a >= 0x0000 && a <= 0xFFFF) {
        memory[a] = d;

        std::cout << memory[a] << std::endl;

        return memory[a];
    }
    return 0x00;
}

void Bus::reset()
{
    cpu.reset();
}

void Bus::clock()
{
    cpu.clock();
}
