#pragma once
#include <iostream>
#include "SDL.h"



//here i am defining values for attributes i'll be using later
#define WIDTH 640
#define HEIGHT 480
#define BALL_SPEED 10
#define SPEED 15
#define SIZE 16
#define PI 3.14159265358979323846



class Game
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Color color;
	bool running;
	int frameCount, timerFPS, lastFrame, fps;
	int playerLives = 3;
	int dodgeCounter = 0;
	SDL_Rect l_paddle, r_paddle, ball, score_board, middle_line;
	float velX, velY;
	std::string score = "";
	int l_s, r_s;
	bool turn;

public :
	Game();
	int start();
	void serve();  //this starts off the game putting the ball in motion
	void update(); //here i am adding update functions to various aspects of the game ie: ball state and paddle positions
	void input(); //here i define the type of controls i am allowing in
	void render(); //here i define what is being put oncscreen the color and framerate

};

