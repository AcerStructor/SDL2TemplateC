/**
 *
 * File Name: init.h
 *
 * Description:
 *      This header file consists of functions that
 *      are responsible for initializing the core components
 *      of SDL2 framework
 *
 */

#ifndef _INIT_H_
#define _INIT_H_

#include "defs.h"
#include "common.h"
#include "structs.h"

SDL_bool init_app(App* app);

void destroy_app(App* app);

#endif // _INIT_H_
