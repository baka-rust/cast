//
//  player.h
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

typedef struct {
    float x;
    float y;
    float theta;
    float move_speed;
    float rot_speed;
} player;


void init_player(player *p);

void player_move_forward(player *p, float dt);
void player_move_backward(player *p, float dt);
void player_turn_left(player *p, float dt);
void player_turn_right(player *p, float dt);
void player_strafe_left(player *p, float dt);
void player_strafe_right(player *p, float dt);

#endif /* player_h */
