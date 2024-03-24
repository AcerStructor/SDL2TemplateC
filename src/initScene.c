#include "structs.h"
#include "initScene.h"

/* --- Global variables --- */
/* ------------------------ */
extern App      app;

/* --- Game Objects --- */
/* -------------------- */



static void update(float delta);
static void render();
static void destroyScene(); // temporary

void initScene()
{
    app.delegate.update     = update;
    app.delegate.render     = render;
    app.delegate.destroy    = destroyScene;
}

static void update(float delta)
{

}

static void render()
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);

    SDL_RenderPresent(app.renderer);
}

static void destroyScene()
{
}
