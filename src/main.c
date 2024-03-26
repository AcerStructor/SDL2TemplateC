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
//#include "initScene.h"
#include "initSplashScreen.h"

static int  last_frame_time = 0;

/* --- Global variables --- */
/* ------------------------ */
SDL_bool    isProgramRunning = SDL_FALSE;
App         app;

/* --- Functions --- */
/* ----------------- */
static void frame_cap(float* delta);

int main(int argc, char* argv[])
{
    isProgramRunning = init_app();  // initialize

    //initScene();
    initSplashScreen();

    while (isProgramRunning == SDL_TRUE)
    {
        /* Process Program Input */
        process_input();
        
        /* Process Frame Capping and delta time */
        float delta;
        frame_cap(&delta);

        /* Process Program */
        app.delegate.update(delta);
        app.delegate.render();

    }

    app.delegate.destroy(); // temporary

    // deallocate app
    destroy_app();

    return EXIT_SUCCESS;
}

static void frame_cap(float* delta)
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }

    *delta = (SDL_GetTicks() - last_frame_time) / 1000.0f;

    last_frame_time = SDL_GetTicks();
}
