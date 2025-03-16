#ifndef GB_CPU_H
#define GB_CPU_H

#include <stdint.h>
#include <stdbool.h>

// CPU clock speed: 4.194304 MHz
#define CPU_CLOCK_SPEED 4194304

// CPU Flags
#define FLAG_Z (1 << 7)  // Zero flag
#define FLAG_N (1 << 6)  // Subtract flag
#define FLAG_H (1 << 5)  // Half carry flag
#define FLAG_C (1 << 4)  // Carry flag

typedef struct {
    // 8-bit registers
    union {
        struct {
            uint8_t f;  // Flag register
            uint8_t a;  // Accumulator
        };
        uint16_t af;    // Combined AF register
    };
    
    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };
    
    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };
    
    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };
    
    uint16_t sp;    // Stack pointer
    uint16_t pc;    // Program counter
    
    bool halted;    // CPU halted state
    bool stopped;   // CPU stopped state
    bool ime;       // Interrupt master enable flag
    
    uint32_t cycles;// Clock cycle counter
} CPU;

// CPU initialization and control functions
void cpu_init(CPU *cpu);
void cpu_reset(CPU *cpu);
int cpu_step(CPU *cpu);

// Flag operations
bool cpu_get_flag(CPU *cpu, uint8_t flag);
void cpu_set_flag(CPU *cpu, uint8_t flag, bool value);

// Interrupt handling
void cpu_handle_interrupts(CPU *cpu);
void cpu_request_interrupt(CPU *cpu, uint8_t interrupt);

#endif // GB_CPU_H 