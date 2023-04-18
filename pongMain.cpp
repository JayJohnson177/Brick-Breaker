#include "Game.h"
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
	srand(time(NULL));
	Game game;
	return game.start();
}