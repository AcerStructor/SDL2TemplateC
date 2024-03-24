#include "defs.h"
#include "structs.h"
#include "initScene.h"
#include "draw.h"

/* --- Global variables --- */
/* ------------------------ */
extern App      app;

/* --- Game Objects --- */
/* -------------------- */
Entity         *entity; // for testing


static void update(float delta);
static void render();
static void destroyScene(); // temporary

void initScene()
{
    app.delegate.update     = update;
    app.delegate.render     = render;
    app.delegate.destroy    = destroyScene;

    entity = (Entity*)malloc(sizeof(Entity));

    entity->sprite = load_texture("res/sprites/placeholder.png");
    entity->pos.x = WINDOW_WIDTH / 2;
    entity->pos.y = WINDOW_HEIGHT / 2;
}

static void update(float delta)
{

}

static void render()
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);

    draw(entity->sprite, entity->pos);

    SDL_RenderPresent(app.renderer);
}

static void destroyScene()
{
    free(entity);
}
