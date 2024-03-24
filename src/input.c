/**
 *
 * File Name: input.c
 *
 */

#include <SDL2/SDL.h>
#include "input.h"

/* --- Global Variable --- */
/* ----------------------- */
extern SDL_bool     isProgramRunning;

/* --- Functions --- */
/* ----------------- */
static void process_key(SDL_Event* e);

void process_input()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                isProgramRunning = SDL_FALSE;
                break;

            case SDL_KEYDOWN:
                process_key(&e);
                break;
        }
    }
}

static void process_key(SDL_Event* e)
{
    switch (e->key.keysym.sym)
    {
        case SDLK_ESCAPE:
            isProgramRunning = SDL_FALSE;
            break;
    }
}
