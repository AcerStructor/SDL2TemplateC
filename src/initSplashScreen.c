#include "structs.h"
#include "initSplashScreen.h"
#include "initScene.h"

/* --- Global Variable --- */
/* ----------------------- */
extern App      app;

/* --- Game Objects --- */
/* -------------------- */


float frameTime     = 0;

/* --- Functions --- */
/* ----------------- */
static void update(float delta);
static void render();
static void destroy();

void initSplashScreen()
{
    putchar('\n');
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, " -----{ SPLASH SCREEN }----- ");

    if (app.delegate.destroy != NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Destroying previous scene");
        app.delegate.destroy();
    }

    /* --- Assign Delegates --- */
    app.delegate.update     = update;
    app.delegate.render     = render;
    app.delegate.destroy    = destroy;

    /* --- Assign Program State --- */
    app.state = STATE_SPLASH_SCREEN;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - App delegate initialized!");

}

static void update(float delta)
{
    frameTime += delta;

    if (frameTime >= 0.3f)
    {
        frameTime = 0; // reset frametime

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Moving to Game Scene\n");
        initScene();
        return;
    }
}

static void render()
{
    SDL_SetRenderDrawColor(app.renderer, 10, 10, 10, 255);
    SDL_RenderClear(app.renderer);


    SDL_RenderPresent(app.renderer);
}

static void destroy()
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Destroyed!\n");
}
