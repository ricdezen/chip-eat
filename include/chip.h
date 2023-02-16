#ifndef CHIP_H
#define CHIP_H

#include "common.h"

#define CHIP8_MEM_SIZE 4096
#define CHIP8_DISP_W 64
#define CHIP8_DISP_H 32

typedef struct {
    // Registers.
    uint8 V[16];

    // Register used to load memory addresses.
    uint16 I;

    // Program counter.
    uint16 PC;

    // Stack pointer.
    uint8 SP;

    // Stack.
    uint16 stack[16];

    // Delay and sound timers.
    uint8 delay_timer;
    uint8 sound_timer;

    // 4k of memory.
    uint8 *memory;
    uint8 *display;
    uint8 display_dirty;
} Chip8;

void Chip8_init(Chip8 *chip);

Chip8 *Chip8_new();

void Chip8_destroy(Chip8 *chip);

void Chip8_free(Chip8 *chip);

#endif