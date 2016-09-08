
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define DRAW_DIST 35

void grid_check(int x, int y) {
	printf("grid check %d, %d\n", x, y);
}

void grid_check_horz(float x, float y, int y_direction) {
	int check_x = (int)x;
	int check_y = (y_direction == 1) ? (int)y : (int)y - 1;
	printf("grid check %d, %d\n", check_x, check_y);
	
}

void cast_horz(float x, float y, float theta) {
	theta = fmod(theta, 360.0); // fit into unit circle for direction mesurement

	int y_direction = (theta > 0 && theta < 180) ? 1 : -1; // up or down
	int x_direction = (theta < 90 || theta > 270) ? 1 : -1; // right or left

	float b_y = (int)y + 1 - y;
	float b_x = fabs(b_y / tan(theta*PI/180));
	
	float dy = y_direction;
	float dx = x_direction * (b_x / b_y);
	
	float start_x = x + (x_direction * b_x);
	float start_y = y + (y_direction * b_y);

	float check_x = start_x;
	float check_y = start_y;
	while (fabsf(check_x - x) < DRAW_DIST && fabs(check_y - y) < DRAW_DIST) {
		int grid_check_x = (int)check_x;
		int grid_check_y = (y_direction == 1) ? (int)check_y : (int)check_y - 1;
		grid_check(grid_check_x, grid_check_y);
		check_x += dx;
		check_y += dy;
	}
}

int main(int argc, char *argv[]) {

	cast_horz(10.5, 10.5, 280);

	return 0;
}
