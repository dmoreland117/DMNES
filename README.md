
# DMNES

This is a simple NES Emulator based on OneLoneCoder's nes video series. It is also my first big project so any help is great.

## Goals

* Acuratly emulate the Cpu, PPU and eventualy the APU

## TODO

* [ ] CPU
  * [ ] Read and write to Bus
  * [x] Registers
    * [x] A
    * [x] X
    * [x] Y
    * [x] FLAGS
    * [x] SP
    * [x] PC
  * [ ] Instructions, For a list of implemented instructions see [instructions](instructions.md)
* [ ] PPU
  * [ ] Add SDL2 rendering
* [ ] APU  
* [ ] Mappers
* [ ] Cart
* [ ] Finish this todo list

## Building

### Windows

run the build.bat file then open up the generated .sln file and build SDL2_UI project.
