#include "app.hpp"

#include <SDL.h>

#include "chip.hpp"

void App_init(App *app) {
    int x = SDL_WINDOWPOS_UNDEFINED;
    int y = SDL_WINDOWPOS_UNDEFINED;
    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    app->window =
        SDL_CreateWindow("Chip-Eat", x, y, CHIP8_DISP_W, CHIP8_DISP_H, flags);
    app->surface =
        SDL_CreateRGBSurface(0, CHIP8_DISP_W, CHIP8_DISP_H, 24, 0, 0, 0, 0);
}

App *App_new() {
    App *app = (App *)malloc(sizeof(App));
    App_init(app);
    return app;
}

void App_destroy(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_FreeSurface(app->surface);
    app->window = NULL;
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
    if (SDL_LockSurface(app->surface) < 0)
        return -1;

    int bpp = app->surface->format->BytesPerPixel;
    uint8 *ptr = (uint8 *)app->surface->pixels;

    for (int i = 0; i < length; i++)
        for (int b = 0; b < bpp; b++)
            ptr[i * bpp + b] = pixels[i] * 255;

    SDL_UnlockSurface(app->surface);

    // Draw the surface on the screen.
    SDL_Surface *screen = SDL_GetWindowSurface(app->window);
    SDL_BlitScaled(app->surface, NULL, screen, NULL);
    SDL_UpdateWindowSurface(app->window);

    return 0;
}
