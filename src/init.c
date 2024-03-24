/**
 *
 * File Name: init.c
 *
 */

#include "defs.h"
#include "init.h"
#include "structs.h"

/* --- global variable --- */
/* ----------------------- */
extern App      app;

SDL_bool init_app()
{
    /* SDL2 Flags */
    const int windowFlags = SDL_WINDOW_MINIMIZED;
    const int rendererFlags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "[ERROR] - Couldn't initialize SDL2: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    app.window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   WINDOW_WIDTH, WINDOW_HEIGHT, windowFlags);

    if (app.window == NULL)
    {
        fprintf(stderr, "[ERROR] - Couldn't initialize SDL2 window: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (app.renderer == NULL)
    {
        fprintf(stderr, "[ERROR] - Couldn't initialize SDL2 renderer: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    return SDL_TRUE;
}

void destroy_app()
{
    IMG_Quit();
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}
