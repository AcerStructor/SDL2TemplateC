/**
 *
 * File Name: structs.h
 *
 * Description:
 *      This header file holds all struct data
 *      that are used for the program such as struct App,
 *      Position and more
 *
 */

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "states.h"

typedef struct {
    void (*update)(float); // <- Pass delta time
    void (*render)(void);
    void (*destroy)(void); // <- temporary for now
} Delegate;

typedef struct {
    SDL_Window     *window;
    SDL_Renderer   *renderer;
    Delegate        delegate;
    ProgramState    state;
} App;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position    pos;
    // TODO:    rotation
    // TODO     scale
} Transform;

typedef struct {
    Transform       transform;
    SDL_Texture*    sprite;
} Entity;

#endif // _STRUCTS_H_
