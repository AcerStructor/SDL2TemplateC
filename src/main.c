/**
 *
 * File Name: main.c
 *
 * Description:
 *      This source file is the main entry point of the
 *      program
 *
 */

#include "defs.h"
#include "common.h"
#include "structs.h"

#include "init.h"
#include "draw.h"
#include "input.h"
#include "render.h"

/* --- Global variables --- */
/* ------------------------ */
static int last_frame_time = 0;
SDL_bool isProgramRunning = SDL_FALSE;

/* --- Game Objects --- */
/* -------------------- */

static void frame_cap();

int main(int argc, char* argv[])
{
    App app;
    
    isProgramRunning = init_app(&app);  // initialize
    
    while (isProgramRunning == SDL_TRUE)
    {
        process_input();
        frame_cap();
        update();
        render(app);
    }

    // deallocate app
    destroy_app(&app);

    return EXIT_SUCCESS;
}


static void frame_cap()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }

    last_frame_time = SDL_GetTicks();
}

