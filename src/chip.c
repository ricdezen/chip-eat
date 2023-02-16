#include "chip.hpp"

#include <stdlib.h>
#include <string.h>

void Chip8_init(Chip8 *chip) {
    memset(chip, 0, sizeof(Chip8));
    chip->memory = (uint8 *)calloc(CHIP8_MEM_SIZE, 1);
    chip->display = (uint8 *)calloc(CHIP8_DISP_W * CHIP8_DISP_H, 1);
}

Chip8 *Chip8_new() {
    Chip8 *chip = (Chip8 *)malloc(sizeof(Chip8));
    Chip8_init(chip);
    return chip;
}

void Chip8_destroy(Chip8 *chip) {
    free(chip->display);
    free(chip->memory);
}

void Chip8_free(Chip8 *chip) {
    Chip8_destroy(chip);
    free(chip);
}
