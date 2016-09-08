//
//  globals.h
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#ifndef globals_h
#define globals_h

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "player.h"


#define PI 3.1415926536

#define SDL_ERR         1

#define SCREEN_WIDTH    640
#define SCREEN_HEIGHT   400
#define SCREEN_SCALE    1


extern SDL_Window *sdl_window;
extern SDL_Surface *sdl_surface;
extern SDL_Event sdl_event;

extern player p;

extern bool sdl_running;

#endif /* globals_h */
