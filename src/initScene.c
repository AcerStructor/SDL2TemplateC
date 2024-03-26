#include "defs.h"
#include "structs.h"
#include "initScene.h"
#include "draw.h"

/* --- Global variables --- */
/* ------------------------ */
extern App      app;

/* --- Game Objects --- */
/* -------------------- */
static Entity  *entity; // for testing


/* --- Functions --- */
/* ----------------- */
static void update(float delta);
static void render();
static void destroyScene();

void initScene()
{
    putchar('\n');
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, " -----{ SCENE }----- ");

    if (app.delegate.destroy != NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "... Destroying previous scene");
        app.delegate.destroy();
    }

    /* --- Assign Delegates --- */
    app.delegate.update     = update;
    app.delegate.render     = render;
    app.delegate.destroy    = destroyScene;

    /* --- Assign Program State --- */
    app.state = STATE_GAME;

    /* --- Allocate Game Objects --- */
    entity = (Entity*)malloc(sizeof(Entity));

    /* --- Load Sprites --- */
    entity->transform.pos.x   = WINDOW_WIDTH  / 2;
    entity->transform.pos.y   = WINDOW_HEIGHT / 2;
    entity->sprite            = load_texture("res/sprites/placeholder.png");
}

static void update(float delta)
{
    entity->transform.pos.x += 150 * delta;
}

static void render()
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);

    draw(entity->sprite, entity->transform);

    SDL_RenderPresent(app.renderer);
}

static void destroyScene()
{
    free(entity);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Entity destroyed!\n");
}
