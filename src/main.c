#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "app.h"
#include "chip.h"

#define OP_PER_SECOND 500
#define OP_MAX_SLEEP (1000 / OP_PER_SECOND)

int main(int argc, char **argv) {
    // Init the app.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Ah gosh dang it man I can't even start!\n");
        return 69;
    }
    App *app = App_new();
    Chip8 *chip = Chip8_new();

    SDL_Event e;
    int quit = 0;
    while (quit == 0) {
        // Start of the frame.
        uint64 start_ticks = SDL_GetTicks64();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = 1;
            // TODO: input.
        }

        // Only draw if the display has been updated.
        if (chip->display_dirty) {
            if (App_draw(app, chip->display, CHIP8_DISP_W * CHIP8_DISP_H) < 0) {
                printf("Could not draw.\n");
                quit = 1;
            }
        }

        // Sleep if necessary.
        uint64 end_ticks = SDL_GetTicks64();
        if (end_ticks < start_ticks + OP_MAX_SLEEP)
            SDL_Delay(OP_MAX_SLEEP - end_ticks + start_ticks);
    }

    // Release the app's resources.
    Chip8_free(chip);
    App_free(app);
    SDL_Quit();
    return 0;
}