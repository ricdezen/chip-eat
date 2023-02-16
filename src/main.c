#include <SDL.h>
#include <stdio.h>

#include "app.h"
#include "chip.h"

int main(int argc, char **argv) {
    // Init the app.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Ah gosh dang it man I can't even start!\n");
        return 69;
    }
    App *app = App_new();

    while (1)
        ;

    // Release the app's resources.
    App_free(app);
    SDL_Quit();
    return 0;
}