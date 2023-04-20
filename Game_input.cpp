
#include "SDL.h"
#include "Game.h"
#include <iostream>


//here i define the type of controls i am allowing in

//#define NUM_SPRITES     4
//SDL_Texture* sprite1;
//SDL_Texture* sprite2;
//SDL_Texture* sprite3;
//SDL_Texture* sprite4;
//SDL_Rect positions[NUM_SPRITES];
//SDL_Rect velocities[NUM_SPRITES];
//SDL_Joystick* joy = NULL;
//SDL_Window* window;
//SDL_Renderer* renderer;
//int i, done;
SDL_Event event;


void Game::input() {
	//Checks whether controller inputs are being used, and moves the paddle based on the desired input method
	if (controllerUsed) {
		short value = getXInput();
		if (value > 0) { transVel = -1; }
		if (value < 0) { transVel = 1; }
		else { transVel = 0; }
		l_paddle.x += value;
	}
	if (!controllerUsed) {
		SDL_Event e;
		const Uint8* keystates = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&e)) if (e.type == SDL_QUIT) running = false;
		if (keystates[SDL_SCANCODE_ESCAPE]) running = false;
		if (keystates[SDL_SCANCODE_LEFT]) {
			l_paddle.x -= SPEED;
			transVel = -1;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			l_paddle.x += SPEED;
			transVel = 1;
		}
		else {
			transVel = 0;
		}
	}

}
	//while (SDL_PollEvent(&event))
	//{
	//	switch (event.type)
	//	{
	//	case SDL_QUIT:
	//	case SDL_KEYDOWN:
	//		done = 1;
	//		break;
	//	case SDL_JOYBUTTONDOWN:
	//		if (event.jbutton.which == 0 && event.jbutton.button == 0) // Button 1 on 1st Joystick
	//		{

	//		}
	//		break;
	//	}
	//}

	//if (joy)
	//{

	//	positions[0].x += SDL_JoystickGetAxis(joy, 0) / 6000;
	//	positions[0].y += SDL_JoystickGetAxis(joy, 1) / 6000;
	//	//if (positions[0].x > WINDOW_WIDTH - sprite_w)
	//	//	positions[0].x = WINDOW_WIDTH - sprite_w;
	//	//if (positions[0].x < 0)
	//	//	positions[0].x = 0;
	//	//if (positions[0].y > WINDOW_HEIGHT - sprite_h)
	//	//	positions[0].y = WINDOW_HEIGHT - sprite_h;
	//	//if (positions[0].y < 0)
	//	//	positions[0].y = 0;
	//}

//Gets the controller state, divides it so it returns between -10 and 10, and returns it
short Game::getXInput() {
	ZeroMemory(&controllerState, sizeof(XINPUT_STATE));
	XInputGetState(0, &controllerState);
	short value = controllerState.Gamepad.sThumbLX;
	value = value / 3276;
	return value;
}
