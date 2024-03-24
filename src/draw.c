/**
 *
 * File Name: draw.c
 *
 */

#include "draw.h"

/* --- global variable --- */
/* ----------------------- */
extern App      app;

SDL_Texture* load_texture(char* filepath)
{
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filepath);

    texture = IMG_LoadTexture(app.renderer, filepath);

    return texture;
}

void draw(SDL_Texture* texture, Position pos)
{
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}
