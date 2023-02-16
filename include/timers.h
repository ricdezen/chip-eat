#ifndef TIMERS_H
#define TIMERS_H

#include "chip.h"

typedef struct {
    Chip8 *chip;
    uint8 should_stop;
} TimerParams;

void start_timers(TimerParams params);

#endif