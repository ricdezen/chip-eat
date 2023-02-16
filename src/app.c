#include "app.h"

#include <SDL.h>

#include "chip.h"

void App_init(App *app) {
    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;
    int flags = SDL_WINDOW_SHOWN;
    app->window =
        SDL_CreateWindow("Chip-Eat", x, y, CHIP8_DISP_W, CHIP8_DISP_H, flags);
    app->surface = SDL_GetWindowSurface(app->window);
}

App *App_new() {
    App *app = (App *)malloc(sizeof(App));
    App_init(app);
    return app;
}

void App_destroy(App *app) {
    SDL_DestroyWindow(app->window);
    app->surface = NULL;
}

void App_free(App *app) {
    App_destroy(app);
    free(app);
}

int App_draw(App *app, uint8 *pixels, int length) {
    // Wrong input image size.
    if (app->surface->w * app->surface->h != length)
        return -1;

    // Write the pixels on the screen.
    int bpp = app->surface->format->BytesPerPixel;
    SDL_LockSurface(app->surface);
    uint8 *pixels = (uint8 *)app->surface->pixels;

    for (int i = 0; i < length; i++)
        for (int b = 0; b < bpp; b++)
            pixels[i * bpp + b] = pixels[i];

    SDL_UnlockSurface(app->surface);
}
