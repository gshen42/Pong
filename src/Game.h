#pragma once
#include <SDL.h>
#include <vector>
#include <memory>
#include "Common.h"
#include "GameObject.h"
#include "Ball.h"

/**
* A singleton class for managing all game-related states.
*/
class Game
{
public:
	~Game();
	static Game& getInstance();
	void quit();
	void run();
	void resetBall();

private:
	Game();
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	void update();
	void render();
	Ball& ball();

	SDL_Window* win;
	SDL_Renderer* rdr;
	bool running;
	std::vector<std::unique_ptr<GameObject>> objs;
	int playerAScore;
	int playerBScore;
};
