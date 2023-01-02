#include "InputHandler.h"
#include "Game.h"
#include <SDL.h>

InputHandler::InputHandler()
{
	SDL_SetRelativeMouseMode(SDL_TRUE);
	y_offset = 0;
}


InputHandler::~InputHandler()
{
}

InputHandler& InputHandler::getInstance()
{
	static InputHandler h;
	return h;
}

void InputHandler::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Game::getInstance().quit();
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_q)
			{
				Game::getInstance().quit();
			}
			break;
		case SDL_MOUSEMOTION:
			y_offset += e.motion.yrel;
			break;
		}
	}
}

int InputHandler::yOffset()
{
	auto tmp = y_offset;
	y_offset = 0;
	return tmp;
}
