# Game Boy Emulator

A Game Boy emulator written in C that aims to emulate the original Nintendo Game Boy hardware.

## Project Structure

```
src/
├── cpu/         - CPU emulation (Sharp LR35902)
├── memory/      - Memory management and mapping
├── ppu/         - Picture Processing Unit emulation
├── apu/         - Audio Processing Unit emulation
├── cartridge/   - ROM and cartridge handling
└── main.c       - Main emulator loop

tests/           - Unit tests
include/         - Header files
```

## Features (Planned)

- [ ] CPU emulation (Sharp LR35902)
- [ ] Memory management
- [ ] PPU (Graphics) emulation
- [ ] Input handling
- [ ] Timer system
- [ ] Sound emulation
- [ ] ROM loading
- [ ] Save states

## Building

Requirements:
- C compiler (GCC or Clang recommended)
- SDL2 (for graphics and input handling)
- CMake (build system)

## Resources

The Game Boy CPU (LR35902) specifications:
- CPU Speed: 4.194304 MHz
- Register Set:
  - 8-bit registers: A, B, C, D, E, F, H, L
  - 16-bit registers: SP (Stack Pointer), PC (Program Counter)
  - Flags: Zero (Z), Subtract (N), Half Carry (H), Carry (C)

## License

This project is licensed under the MIT License - see the LICENSE file for details.