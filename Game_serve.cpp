
#include "SDL.h"
#include "Game.h"
#include <stdlib.h>
#include <time.h>



//this starts off the game putting the ball in motion
void Game::serve() {
	//Randomly sets the ball position between the two walls in the arena.
	ball.x = rand() % ((WIDTH - 15) - 11) + 10;
	l_paddle.y = r_paddle.y = HEIGHT - l_paddle.h;
	if (turn) {
		//ball.x = l_paddle.x + (l_paddle.w * 4);
		ball.x = rand() % ((WIDTH - 15) - 11) + 10;
		velX = BALL_SPEED / 2;
	}
	else {
		//ball.x = r_paddle.x - (r_paddle.w * 4);
		ball.x = rand() % ((WIDTH - 15) - 11) + 10;
		velX = -BALL_SPEED / 2;
	}
	velX = 0;
	velY = BALL_SPEED;
	ball.y = 40;
	turn = !turn;
}
