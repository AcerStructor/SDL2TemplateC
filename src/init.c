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

    /* ----- Initializing SDL2 ----- */
    /* ----------------------------- */
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, " -----{ INITIALIZING SDL2 }----- \n\n");

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "ERROR: [X] - Couldn't initialize SDL2: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - SDL2 Initialized!\n");
    
    /* ----- Initializing Window ----- */
    /* ------------------------------- */
    app.window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  WINDOW_WIDTH, WINDOW_HEIGHT, windowFlags);

    if (app.window == NULL)
    {
        fprintf(stderr, "ERROR: [X] - Couldn't initialize SDL2 window: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Window initialized!\n");

    /* ----- Setting Hint ----- */
    /* ------------------------ */
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Hint set to \"linear\"\n");

    /* ----- Initializing Renderer ----- */
    /* --------------------------------- */
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (app.renderer == NULL)
    {
        fprintf(stderr, "ERROR: [X] - Couldn't initialize SDL2 renderer: %s\n", SDL_GetError());
        return SDL_FALSE;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Renderer initialized\n");

    /* ----- Initializing IMG ----- */
    /* ---------------------------- */
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - IMG initialized\n\n");

    /* ----- Initialization FInished ----- */
    /* ----------------------------------- */
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, " -----{ INITIALIZATION FINISHED }----- \n\n");

    return SDL_TRUE;
}

void destroy_app()
{
    /* ----- Deallocating ----- */
    /* ------------------------ */
    putchar('\n');
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, " -----{ DEALLOCATING SDL2 }----- \n\n");

    IMG_Quit();
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - IMG deallocated \n");
    
    SDL_DestroyRenderer(app.renderer);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Renderer deallocated \n");
    
    SDL_DestroyWindow(app.window);
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "[✓] - Window deallocated \n\n");

    SDL_Quit();
}
