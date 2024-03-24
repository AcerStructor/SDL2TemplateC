/**
 *
 * File Name: draw.h
 *
 * Description:
 *      This header file consists of functions
 *      related to loading and drawing textures
 *      which can serve as game sprites
 *
 */

#ifndef _DRAW_H_
#define _DRAW_H_

#include "common.h"
#include "structs.h"

SDL_Texture* load_texture(char* filepath);

void draw(SDL_Texture* texture, Position pos);

#endif // _DRAW_H_
