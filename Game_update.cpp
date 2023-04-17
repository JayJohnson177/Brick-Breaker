
#include "SDL.h"
#include "Game.h"
#include <stdlib.h>
#include <time.h>


//here i am adding update functions to various aspects of the game ie: ball state and paddle positions
void Game::update() {
	/*if (SDL_HasIntersection(&ball, &r_paddle)) {
		double rel = (r_paddle.y + (r_paddle.h / 2)) - (ball.y + (SIZE / 2));
		double norm = rel / (r_paddle.h / 2);
		double bounce = norm * (5 * PI / 12);
		velX = -BALL_SPEED * cos(bounce);
		velY = BALL_SPEED * -sin(bounce);
	}*/

	//hits the player
	if (SDL_HasIntersection(&ball, &l_paddle)) {
		double rel = (l_paddle.y + (l_paddle.h / 2)) - (ball.y + (SIZE / 2));
		double norm = rel / (l_paddle.h / 2);
		double bounce = norm * (5 * PI / 12);
		velX = BALL_SPEED * cos(bounce);
		velY = -BALL_SPEED * sin(bounce); 
	}

	//Checks for collision between the three main walls, flipping the X velocity upon hitting
	//the left or right walls, and flipping the Y velocity upon hitting the top wall. 
	if (SDL_HasIntersection(&ball, &l_wall) || SDL_HasIntersection(&ball, &r_wall)) { velX = -velX; }
	if (SDL_HasIntersection(&ball, &t_wall)) { velY = -velY; }


	if (ball.y > r_paddle.y + (r_paddle.h / 2)) r_paddle.y += SPEED;
	if (ball.y < r_paddle.y + (r_paddle.h / 2)) r_paddle.y -= SPEED;
	if (ball.x <= 0) { r_s++; serve(); }
	if (ball.x + SIZE >= WIDTH) { l_s++; serve(); }
	if (ball.y <= 0 || ball.y + SIZE >= HEIGHT) velY = -velY;

	//hits the bottom
	if (ball.y <=0) 
	{
		velY = -velY;
	}
	else if (ball.y + SIZE >= HEIGHT)
	{
		serve();
		playerLives--;

		if (playerLives == 0)
		{
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}

	}

 else if (SDL_HasIntersection(&ball, &t_wall)) {
 velY = -velY;
 }

	ball.x += velX;
	ball.y += velY;

	if (l_paddle.y < 0)l_paddle.y = 0;
	if (l_paddle.y + l_paddle.h > HEIGHT)l_paddle.y = HEIGHT - l_paddle.h;
	if (r_paddle.y < 0)r_paddle.y = 0;
	if (r_paddle.y + r_paddle.h > HEIGHT)r_paddle.y = HEIGHT - r_paddle.h;
}
