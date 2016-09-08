//
//  casting.h
//  cast
//
//  Created by Sam Frank on 9/7/16.
//  Copyright © 2016 sjf. All rights reserved.
//

#ifndef casting_h
#define casting_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graphics.h"


#define DRAW_DIST 30
#define FOV 60.0

#define PROJECTION_WIDTH 320
#define PROJECTION_HEIGHT 180

#define MAP_HEIGHT 10
#define MAP_WIDTH 10

extern int map[10][10];


int grid_check(int x, int y);
float dist(float x_1, float y_1, float x_2, float y_2);

float cast_vert(float x, float y, float theta, int x_direction, int y_direction);
float cast_horz(float x, float y, float theta, int x_direction, int y_direction);

float cast(float x, float y, float theta);
void cast_all(float x, float y, float theta);

#endif /* casting_h */
