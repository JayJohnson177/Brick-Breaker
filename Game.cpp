#include <iostream>
#include "SDL.h"
#include "Game.h"

Game::Game() {

}
int Game::start() {


	//my off switch incase something doesnt work
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer())" << std::endl;

	running = 1;
	static int lastTime = 0;

	//defining the dimensions and positions of each object involved in the game
	color.r = color.g = color.b = 255;
	brickColor.r = 255;
	brickColor.g = 0;
	brickColor.b = 0;

	wallColor.r = wallColor.g = wallColor.b = 0;


	//paddles
	l_s = r_s = 0;
	l_paddle.x = WIDTH / 2 - 20; l_paddle.h = HEIGHT / 16;
	l_paddle.y = (HEIGHT / 2) - (l_paddle.h / 2);
	l_paddle.w = 80;
	//r_paddle = l_paddle;
	//r_paddle.x = WIDTH - r_paddle.w - 32;
	//ball
	ball.w = ball.h = SIZE;
	////centreline
	//middle_line.x = (WIDTH / 2) - 5;
	//middle_line.y = 0;
	//middle_line.w = 10;
	//middle_line.h = HEIGHT;

	l_wall.x = 0;
	l_wall.y = 0;
	l_wall.w = 10;
	l_wall.h = HEIGHT;

	r_wall.x = WIDTH - 10;
	r_wall.y = 0;
	r_wall.w = 10;
	r_wall.h = HEIGHT;

	t_wall.x = 0;
	t_wall.y = 0;
	t_wall.w = WIDTH;
	t_wall.h = 10;

	//Buffer for the positions of the spawned bricks
	int bufferX = 0;
	int bufferY = 40;
	//Changes the vector size to match the amount of bricks we're spawning
	brickPos.resize(numSpawnedBricks);
	brickState.resize(numSpawnedBricks);

	//For every brick, sets its parameters, and changes the buffer position over slightly 
	for (int i = 0; i < numSpawnedBricks; i++) {
		brickPos[i].w = 40;
		brickPos[i].h = 30;
		brickPos[i].x = bufferX;
		brickPos[i].y = bufferY;
		//Randomly determines how much health the associated brick has
		brickState[i] = rand() % 4;

		bufferX = bufferX + 43;
		//If it starts spawning bricks offscreen, moves the Y buffer down and resets the X buffer
		//resulting in new bricks spawning on the next line
		if (bufferX >= WIDTH) {
			bufferY += 35;
			bufferX = 0;
		}
	}

	//starting the game
	serve();

	//running state of the game
	while (running) {
		lastFrame = SDL_GetTicks();
		if (lastFrame >= (lastTime + 1000)) {
			lastTime = lastFrame;
			fps = frameCount;
			frameCount = 0;
		}

		//main cycle, accepting inputs from controller or keyboards,updating the game state and then displaying it to the window.
		input();
		update();
		render();
	}
	//ending the game,destroying the window,rederer and ending the loop

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
