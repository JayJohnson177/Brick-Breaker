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
	//paddles
	l_s = r_s = 0;
	l_paddle.x = WIDTH/2 -20; l_paddle.h = HEIGHT / 16;
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