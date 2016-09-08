//
//  casting.c
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#include "casting.h"

int map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


int grid_check(int x, int y) {
    if (x < 0 || x >= MAP_HEIGHT || y < 0 || y >= MAP_WIDTH) {
        return 0;
    }
    return map[x][y];
}

float dist(float x_1, float y_1, float x_2, float y_2) {
    return sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
}

float cast_vert(float x, float y, float theta, int x_direction, int y_direction) {
    float b_x = (x_direction == 1) ? (int)x + 1 - x : x - (int)x;
    float b_y = fabs(b_x * tan(theta*PI/180));
    
    float dx = x_direction;
    float dy = y_direction * (b_y / b_x);
    
    float start_x = x + (x_direction * b_x);
    float start_y = y + (y_direction * b_y);
    
    float check_x = start_x;
    float check_y = start_y;
    int wall = 0;
    while (fabs(check_x - x) < DRAW_DIST && fabs(check_y -y) < DRAW_DIST) {
        int grid_check_x = (x_direction == 1) ? (int)check_x : (int)check_x - 1;
        int grid_check_y = (int)check_y;
        wall = grid_check(grid_check_x, grid_check_y);
        if (wall) {
            return dist(x, y, check_x, check_y);
        }
        check_x += dx;
        check_y += dy;
    }
    
    return INFINITY;
}

float cast_horz(float x, float y, float theta, int x_direction, int y_direction) {
    float b_y = (y_direction == 1) ? (int)y + 1 - y : y - (int)y;
    float b_x = fabs(b_y / tan(theta*PI/180));
    
    float dy = y_direction;
    float dx = x_direction * (b_x / b_y);
    
    float start_x = x + (x_direction * b_x);
    float start_y = y + (y_direction * b_y);
    
    float check_x = start_x;
    float check_y = start_y;
    int wall = 0;
    while (fabs(check_x - x) < DRAW_DIST && fabs(check_y -y) < DRAW_DIST) {
        int grid_check_x = (int)check_x;
        int grid_check_y = (y_direction == 1) ? (int)check_y : (int)check_y - 1;
        wall = grid_check(grid_check_x, grid_check_y);
        if (wall) {
            return dist(x, y, check_x, check_y);
        }
        check_x += dx;
        check_y += dy;
    }
    
    return INFINITY;
}

float cast(float x, float y, float theta) {
    theta = fmod(theta, 360.0);
    int x_direction = (theta < 90 || theta > 270) ? 1 : -1; // right or left
    int y_direction = (theta > 0 && theta < 180) ? 1 : -1; // up or down
    
    float dist_vert = cast_vert(x, y, theta, x_direction, y_direction);
    float dist_horz = cast_horz(x, y, theta, x_direction, y_direction);
    
    float wall_dist = (dist_horz < dist_vert) ? dist_horz : dist_vert;
    
    return wall_dist;
}

void cast_all(float x, float y, float theta) {
    float deg_per_col = FOV / SCREEN_WIDTH;
    float current_cast;
    int col = 0;
    for (float t = theta - FOV/2; t < theta + FOV/2; t += deg_per_col, col++) {
        current_cast = cast(x, y, t);
        if (current_cast != INFINITY) {
            int wall_height = (SCREEN_HEIGHT / (current_cast * cos((theta - t)*PI/180))); // fix fisheye
            draw_wall(col, wall_height);
        }
    }
}
