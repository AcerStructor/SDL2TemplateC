#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} App;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    SDL_Texture* sprite;
} Entity;

#endif // _STRUCTS_H_
