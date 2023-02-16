#ifndef APP_H
#define APP_H

#include <SDL.h>

#include "common.h"

typedef struct {
    SDL_Window *window;
    SDL_Surface *surface;
} App;

void App_init(App *app);

App *App_new();

void App_destroy(App *app);

void App_free(App *app);

/**
 * @param pixels Array of black (0) and white (non-zero) pixels.
 * @param length Length of the array, must be equal to the size of the window's
 * surface.
 * @return int 0 if everything went ok, and -1 if something went wrong.
 */
int App_draw(App *app, uint8 *pixels, int length);

#endif