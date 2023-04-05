
#include "SDL.h"
#include "Game.h"
#include <stdlib.h>
#include <time.h>



//this starts off the game putting the ball in motion
void Game::serve() {
	ball.x = rand()% WIDTH - l_paddle.w;
	l_paddle.y = r_paddle.y = HEIGHT-l_paddle.h;
	if (turn) {
		ball.x = l_paddle.x + (l_paddle.w * 4);
		velX = BALL_SPEED / 2;
	}
	else {
		ball.x = r_paddle.x - (r_paddle.w * 4);
		velX = -BALL_SPEED / 2;
	}
	velX = 0;
	velY = BALL_SPEED;
	ball.y = 0;
	turn = !turn;
}