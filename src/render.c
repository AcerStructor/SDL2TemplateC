/**
 *
 * File Name: render.c
 *
 */


#include "render.h"

extern Entity* entities;

static void renderDrawColor(App app);
static void renderEntities(Entity* entities);

void render(App app)
{
    renderDrawColor(app);

    renderEntities(entities);

    SDL_RenderPresent(app.renderer);
}

static void renderEntities(Entity* entities)
{
    // TODO
}
static void renderDrawColor(App app)
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);
}
