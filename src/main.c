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
#include "update.h"
#include "render.h"

/* --- Global variables --- */
/* ------------------------ */
SDL_bool isProgramRunning = SDL_FALSE;

/* --- Game Objects --- */
/* -------------------- */
Entity* entities; 

int main(int argc, char* argv[])
{
    App app;
    
    isProgramRunning = init_app(&app);  // initialize
    
    while (isProgramRunning == SDL_TRUE)
    {
        process_input();
        update();
        render(app);
    }

    // deallocate app
    destroy_app(&app);

    return EXIT_SUCCESS;
}
