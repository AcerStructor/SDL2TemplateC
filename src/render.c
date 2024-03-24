/**
 *
 * File Name: render.c
 *
 */


#include "render.h"

static void renderDrawColor(App app);

void render(App app)
{
    renderDrawColor(app);

    SDL_RenderPresent(app.renderer);
}

static void renderDrawColor(App app)
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);
}
