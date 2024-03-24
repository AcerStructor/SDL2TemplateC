/**
 *
 * File Name: draw.c
 *
 */

#include "draw.h"

SDL_Texture* load_texture(App app, char* filename)
{
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app.renderer, filename);

    return texture;
}

void draw(App app, SDL_Texture* texture, Position pos)
{
    SDL_Rect dest;

    dest.x = pos.x;
    dest.y = pos.y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}
