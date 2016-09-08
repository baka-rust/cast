//
//  player.c
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#include "player.h"

void init_player(player *p) {
    p->x = 5.01;
    p->y = 5.01;
    p->theta = 270.01;
    p->move_speed = 2;
    p->rot_speed = 80;
}

void player_move_forward(player *p, float dt) {
    float move_x = p->move_speed * cos(p->theta * PI/180);
    float move_y = p->move_speed * sin(p->theta * PI/180);
    p->x += move_x * dt;
    p->y += move_y * dt;
}

void player_move_backward(player *p, float dt) {
    float move_x = p->move_speed * cos(p->theta * PI/180);
    float move_y = p->move_speed * sin(p->theta * PI/180);
    p->x -= move_x * dt;
    p->y -= move_y * dt;
}

void player_turn_left(player *p, float dt) {
    p->theta -= p->rot_speed * dt;
}

void player_turn_right(player *p, float dt) {
    p->theta += p->rot_speed * dt;
}

void player_strafe_left(player *p, float dt) {
    float move_x = p->move_speed * cos((p->theta - 90) * PI/180);
    float move_y = p->move_speed * sin((p->theta - 90) * PI/180);
    p->x += move_x * dt;
    p->y += move_y * dt;
}

void player_strafe_right(player *p, float dt) {
    float move_x = p->move_speed * cos((p->theta + 90) * PI/180);
    float move_y = p->move_speed * sin((p->theta + 90) * PI/180);
    p->x += move_x * dt;
    p->y += move_y * dt;
}