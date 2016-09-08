import math
import sys

DRAW_SIZE = 50
MAP_X = 30
MAP_Y = 30
DRAW_DIST = 30

def draw_line(x, y, theta, length, canvas):
	theta = math.fmod(theta, 360)
	end_x = length * 2 * math.cos(math.radians(theta))
	end_y = length * 2 * math.sin(math.radians(theta))

	canvas.create_line(
		x*DRAW_SIZE,
		y*DRAW_SIZE,
		(x + end_x)*DRAW_SIZE,
		(y + end_y)*DRAW_SIZE,
		fill="red"
	)

def draw_dot(x, y, canvas, radius=.1):
	delta = radius/2
	canvas.create_oval(
		(x-delta)*DRAW_SIZE,
		(y-delta)*DRAW_SIZE,
		(x+delta)*DRAW_SIZE,
		(y+delta)*DRAW_SIZE,
		fill="green"
	)

def draw_check(x, y, canvas):
	print "grid check " + str(x) + ", " + str(y)
	canvas.create_rectangle(
		x*DRAW_SIZE,
		y*DRAW_SIZE,
		(x+1)*DRAW_SIZE,
		(y+1)*DRAW_SIZE,
		outline="white",
	)

def run_vert(x, y, theta, canvas):
	draw_line(x, y, theta, DRAW_DIST, canvas)
	theta = math.fmod(theta, 360)
	if (theta == 90 or theta == 270):
		return

	x_direction = 1 if (theta < 90 or theta > 270) else -1
	y_direction = 1 if (theta > 0 and theta < 180) else -1

	b_x = int(x) + 1 - x
	b_y = math.fabs(b_x * math.tan(math.radians(theta)))

	dx = x_direction
	dy = y_direction * (b_y / b_x)

	start_x = x + (x_direction * b_x)
	start_y = y + (y_direction * b_y)

	check_x = start_x
	check_y = start_y
	while math.fabs(check_x -x) < DRAW_DIST and math.fabs(check_y - y) < DRAW_DIST:
		draw_dot(check_x, check_y, canvas)
		if x_direction == -1:
			draw_check(int(check_x) - 1, int(check_y), canvas)
		else:
			draw_check(int(check_x), int(check_y), canvas)
		check_x += dx
		check_y += dy

def run_horz(x, y, theta, canvas):
	draw_line(x, y, theta, DRAW_DIST, canvas)
	theta = math.fmod(theta, 360)
	if (theta == 0 or theta == 180):
		return	

	y_direction = 1 if (theta > 0 and theta < 180) else -1
	x_direction = 1 if (theta < 90 or theta > 270) else -1

	b_y = int(y) + 1 - y if (y_direction == 1) else y - int(y)
	b_x = math.fabs(b_y / math.tan(math.radians(theta)))

	dy = y_direction
	dx = x_direction * (b_x / b_y)

	start_x = x + (x_direction * b_x)
	start_y = y + (y_direction * b_y)

	check_x = start_x
	check_y = start_y
	while math.fabs(check_x - x) < DRAW_DIST and math.fabs(check_y - y) < DRAW_DIST:
		draw_dot(check_x, check_y, canvas)
		if y_direction == -1:
			draw_check(int(check_x), int(check_y) - 1, canvas)
		else:
			draw_check(int(check_x), int(check_y), canvas)
		check_x += dx
		check_y += dy

def tk_render(theta):
	import Tkinter
	view = Tkinter.Tk()
	canvas = Tkinter.Canvas(view, width = DRAW_SIZE * MAP_X, height = DRAW_SIZE * MAP_Y)
	canvas.pack()
	for y in range(MAP_Y):
		for x in range(MAP_X):
			canvas.create_rectangle(x*DRAW_SIZE, y*DRAW_SIZE, x*DRAW_SIZE + DRAW_SIZE, y*DRAW_SIZE + DRAW_SIZE, fill = "blue")
	
	run_horz(10.5, 10.7, theta, canvas)
	#run_vert(10.7, 10.7, theta, canvas)

	view.mainloop()

if __name__ == "__main__":
	tk_render(float(sys.argv[1]))
