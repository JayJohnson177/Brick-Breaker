#include "SDL.h"
#include "Game.h"


//here i define what is being put oncscreen the color and framerate
void Game::render() {
	SDL_RenderClear(renderer);
	SDL_Rect Background = { 0,0,WIDTH,HEIGHT };
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(renderer, &Background);
	frameCount++;
	timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60)) {
		SDL_Delay((1000 / 60) - timerFPS);
	}
	//here are the game components
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
	SDL_RenderFillRect(renderer, &l_paddle);
	SDL_RenderFillRect(renderer, &r_paddle);
	SDL_RenderFillRect(renderer, &ball);
	SDL_RenderFillRect(renderer, &middle_line);

	SDL_SetRenderDrawColor(renderer, wallColor.r, wallColor.g, wallColor.b, 255);
	SDL_RenderFillRect(renderer, &r_wall);
	SDL_RenderFillRect(renderer, &l_wall);
	SDL_RenderFillRect(renderer, &t_wall);

	//SDL_SetRenderDrawColor(renderer, brickColor.r, brickColor.g, brickColor.b, 255);
	//For each brick, checks the health, and changes the colour based on its health 
	//before rendering it after the switch statement
	for (int i = 0; i < numSpawnedBricks; i++) {
		switch (brickState[i]) {
		case 0:
			brickPos[i].x = -5000;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			break;
		case 1:
			SDL_SetRenderDrawColor(renderer, 78, 0, 255, 255);
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 155, 255, 0, 255);
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			break;
		}
		SDL_RenderFillRect(renderer, &brickPos[i]);
	}

	SDL_RenderPresent(renderer);
}



