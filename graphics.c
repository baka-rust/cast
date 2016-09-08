//
//  graphics.c
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#include "graphics.h"

void draw_wall(int col, int height) {
    int y_start = (SCREEN_HEIGHT - height) / 2;
    if (y_start < 0) y_start = 0;
    for (int y = y_start; y < y_start + height && y < SCREEN_HEIGHT + 1; y++) {
        set_pixel(col, y, 0xFF, 0x00, 0x00);
    }
}

void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
    Uint32 *pixels = (Uint32 *)sdl_surface->pixels;
    pixels[(y * sdl_surface->w) + x] = SDL_MapRGB(sdl_surface->format, r, g, b);
}