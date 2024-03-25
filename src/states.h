/**
 *
 * FIle Name: states.h
 *
 * Description:
 *      This header file consists of program states
 *      in order to manage which state the program is in.
 *      In short, it is the main implementation for
 *      enums
 */

#ifndef _STATES_H_
#define _STATES_H_

typedef enum {
    STATE_SPLASH_SCREEN,
    STATE_MAIN_MENU,
    STATE_GAME,
    STATE_GAME_OVER,
} ProgramState;

#endif // _STATES_H_
