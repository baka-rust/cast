//
//  graphics.h
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#ifndef graphics_h
#define graphics_h

#include <stdio.h>

#include <SDL2/SDL.h>

#include "globals.h"


void draw_wall(int col, int height);

void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);

#endif /* graphics_h */
