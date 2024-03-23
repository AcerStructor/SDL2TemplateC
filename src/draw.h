#ifndef _DRAW_H_
#define _DRAW_H_

#include "common.h"
#include "structs.h"

SDL_Texture* load_texture(App app, char* filename);

void draw(App app, SDL_Texture* texture, Position pos);

#endif // _DRAW_H_
