//
//  main.c
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "globals.h"
#include "casting.h"
#include "graphics.h"

SDL_Surface *sdl_surface;
player p;

int main(int argc, const char * argv[]) {
    
    init_player(&p);
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL. SDL_Error: %s\n", SDL_GetError());
        exit(SDL_ERR);
    }
    
    SDL_Window *sdl_window = SDL_CreateWindow("SDL_TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCREEN_SCALE, SCREEN_HEIGHT * SCREEN_SCALE, SDL_WINDOW_SHOWN);
    if (!sdl_window) {
        printf("Could not create SDL window. SDL_Error: %s\n", SDL_GetError());
        exit(SDL_ERR);
    }
    
    sdl_surface = SDL_GetWindowSurface(sdl_window);
    SDL_Event sdl_event;
    
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    float dt = 0;
    const Uint8 *keyboard_state;
    
    bool sdl_running = true;
    while (sdl_running) {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        dt = (float)((NOW - LAST)*1000 / SDL_GetPerformanceFrequency()) * 0.001;
        
        while (SDL_PollEvent(&sdl_event) != 0) {
            if (sdl_event.type == SDL_QUIT) {
                sdl_running = false;
            }
        }
        
        keyboard_state = SDL_GetKeyboardState(NULL);
        if (keyboard_state[SDL_SCANCODE_W]) {
            player_move_forward(&p, dt);
        } else if (keyboard_state[SDL_SCANCODE_S]) {
            player_move_backward(&p, dt);
        }
        if (keyboard_state[SDL_SCANCODE_A]) {
            player_turn_left(&p, dt);
        } else if (keyboard_state[SDL_SCANCODE_D]) {
            player_turn_right(&p, dt);
        }
        if (keyboard_state[SDL_SCANCODE_Q]) {
            player_strafe_left(&p, dt);
        } else if (keyboard_state[SDL_SCANCODE_E]) {
            player_strafe_right(&p, dt);
        }
        
        SDL_FillRect(sdl_surface, NULL, SDL_MapRGB(sdl_surface->format, 0xFF, 0xFF, 0xFF));
        
        cast_all(p.x, p.y, p.theta);
        
        SDL_UpdateWindowSurface(sdl_window);
    }
    
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    
    return 0;
}
