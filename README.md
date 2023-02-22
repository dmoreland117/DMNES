
# DMNES

This is a simple NES Emulator. It is also my first big project so any help is great.

## Goals

* Acuratly emulate the Cpu, PPU and eventualy the APU

## TODO

* [ ] CPU
  * [ ] Read and write to Bus
  * [ ] Registers
    * [x] A
    * [x] X
    * [x] Y
    * [x] FLAGS
    * [ ] SP
    * [ ] PC
  * [ ] Opcodes
    * [ ] 0x00 BRK
    * [ ] 0x01 BPL
    * [ ] 0x02 JSR
    * [ ] 0x03 BMI
    * [ ] 0x04 RTI
    * [ ] 0x05 BVC
    * [ ] 0x06 RTS
    * [ ] 0x07 BVS
    * [ ] 0x08 NOP
    * [ ] 0x09 BCC
    * [ ] 0x0A LDY
    * [ ] 0x0B BCS
    * [ ] 0x0C CPY
    * [ ] 0x0D BNE
    * [ ] 0x0E CPX
    * [ ] 0x0F BEQ
* [ ] PPU
  * [ ] Add SDL2 rendering
* [ ] APU  
* [ ] Cart

## Building

Open the DMNES.sin file and build. I dont have SDL2 in the project yet so you dont need it.
