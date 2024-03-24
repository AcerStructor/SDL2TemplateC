#include "update.h"

static int last_frame_time = 0;

static void frame_cap()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }

    last_frame_time = SDL_GetTicks();
}

void update()
{
    frame_cap();
    // float delta = (SDL_GetTicks() - last_frame_time) / 1000.0f;
}
