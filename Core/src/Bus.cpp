#include "Bus.h"

#include <iostream>

Bus::Bus()
{
    for (size_t i = 0; i < 2044; i++)
    {
        memory[i] = 0x00;
    }

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
    if (a >= ADDR_2KB_RAM_BEGIN && a <= ADDR_2KB_RAM_END) {
        return memory[a];
    }
    return 0x00;
}

Byte Bus::write(Word a, Byte d)
{
    if (a >= ADDR_2KB_RAM_BEGIN && a <= ADDR_2KB_RAM_END) {
        memory[0x0000] = d;

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
