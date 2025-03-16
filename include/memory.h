#ifndef GB_MEMORY_H
#define GB_MEMORY_H

#include <stdint.h>

// Memory map constants
#define ROM_BANK_0_START     0x0000
#define ROM_BANK_0_END       0x3FFF
#define ROM_BANK_N_START     0x4000
#define ROM_BANK_N_END       0x7FFF
#define VRAM_START           0x8000
#define VRAM_END             0x9FFF
#define EXTERNAL_RAM_START   0xA000
#define EXTERNAL_RAM_END     0xBFFF
#define WORK_RAM_START       0xC000
#define WORK_RAM_END         0xDFFF
#define ECHO_RAM_START       0xE000
#define ECHO_RAM_END         0xFDFF
#define OAM_START            0xFE00
#define OAM_END              0xFE9F
#define IO_REGISTERS_START   0xFF00
#define IO_REGISTERS_END     0xFF7F
#define HRAM_START           0xFF80
#define HRAM_END             0xFFFE
#define IE_REGISTER          0xFFFF

typedef struct {
    uint8_t rom_bank_0[0x4000];     // 16KB ROM Bank 0
    uint8_t rom_bank_n[0x4000];     // 16KB ROM Bank n
    uint8_t vram[0x2000];           // 8KB Video RAM
    uint8_t external_ram[0x2000];   // 8KB External RAM
    uint8_t work_ram[0x2000];       // 8KB Work RAM
    uint8_t oam[0xA0];             // Object Attribute Memory
    uint8_t io_registers[0x80];     // I/O Registers
    uint8_t hram[0x7F];            // High RAM
    uint8_t ie_register;           // Interrupt Enable Register
} Memory;

// Memory initialization and control
void memory_init(Memory *memory);
void memory_reset(Memory *memory);

// Memory access
uint8_t memory_read_byte(Memory *memory, uint16_t address);
void memory_write_byte(Memory *memory, uint16_t address, uint8_t value);
uint16_t memory_read_word(Memory *memory, uint16_t address);
void memory_write_word(Memory *memory, uint16_t address, uint16_t value);

// DMA transfer
void memory_dma_transfer(Memory *memory, uint8_t start);

#endif // GB_MEMORY_H 