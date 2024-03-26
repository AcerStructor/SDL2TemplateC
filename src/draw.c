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

void draw(SDL_Texture* texture, Transform transform)
{
    /* Declaration */
    SDL_Rect dest;
    Position localOrigin;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    /* Set Local Origin */
    localOrigin.x = dest.w / 2;
    localOrigin.y = dest.h / 2;

    /* Set local rect position */
    dest.x = transform.pos.x - localOrigin.x;
    dest.y = transform.pos.y - localOrigin.y;
    
    /* Draw to game scene */
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}
