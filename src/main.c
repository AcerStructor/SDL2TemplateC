/**
 *
 * File Name: main.c
 *
 * Description:
 *      This file is the main entry point of the
 *      program
 *
 */

#include "defs.h"
#include "common.h"
#include "structs.h"

#include "init.h"
#include "draw.h"
#include "input.h"
#include "update.h"

/* Global variables */
SDL_bool isProgramRunning = SDL_FALSE;

/* functions */
void update();
void render(App app);

int main(int argc, char* argv[])
{
    App app;
    
    isProgramRunning = init_app(&app); // initialize

    // init entities TODO
    while (isProgramRunning == SDL_TRUE)
    {
        process_input();
        update();
        render(app);
    }

    // deallocate entities

    // deallocate app
    destroy_app(&app);

    return EXIT_SUCCESS;
}

void update()
{
    frame_cap();
    // float delta = process_delta();
}

void render(App app)
{
    SDL_SetRenderDrawColor(app.renderer, 12, 12, 12, 255);
    SDL_RenderClear(app.renderer);

    SDL_RenderPresent(app.renderer);
}
