#include "Game.h"
#include "InputHandler.h"
#include "Player.h"
#include "AI.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;

constexpr int MID_NUM = 18;

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow(
		"Pong",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0
	);
	rdr = SDL_CreateRenderer(
		win,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	running = true;

	auto playerA = new Player(
		PLAYERA_INIT_X,
		PLAYERA_INIT_Y,
		PLAYER_W,
		PLAYER_H
	);

	auto playerB = new AI(
		PLAYERB_INIT_X,
		PLAYERB_INIT_Y,
		PLAYER_W,
		PLAYER_H
	);

	auto ball = new Ball(
		BALL_INIT_X,
		BALL_INIT_Y,
		BALL_RADIUS,
		BALL_INIT_VX,
		BALL_INIT_VY,
		playerA,
		playerB
	);

	playerB->trackBall(ball);

	objs.emplace_back(playerA);
	objs.emplace_back(playerB);
	objs.emplace_back(ball);

	playerAScore = 0;
	playerBScore = 0;
}

Game::~Game()
{
	SDL_DestroyWindow(win);
	SDL_Quit();
}

Game& Game::getInstance()
{
	static Game g;
	return g;
}

void Game::quit()
{
	running = false;
}

void Game::run()
{
	while (running)
	{
		InputHandler::getInstance().update();
		update();
		render();
	}
}

void Game::update()
{
	for (auto& obj : objs)
	{
		obj->update();
	}

	if (ball().x < 0)
	{
		playerAScore++;
		resetBall();
	}

	if (ball().x + ball().w > SCREEN_WIDTH)
	{
		playerBScore++;
		resetBall();
	}

}

void Game::render()
{
	// render the table
	SDL_SetRenderDrawColor(rdr, 0, 0, 0, 255);
	SDL_RenderClear(rdr);
	SDL_SetRenderDrawColor(rdr, 171, 172, 170, 255);
	SDL_Rect boarders[2];
	boarders[0] = { 0, 0, SCREEN_WIDTH, BOARDER_WIDTH };
	boarders[1] = { 0, SCREEN_HEIGHT - BOARDER_WIDTH,
					SCREEN_WIDTH, BOARDER_WIDTH };
	SDL_RenderFillRects(rdr, boarders, 2);
	SDL_Rect midline[MID_NUM];
	for (int i = 0; i < MID_NUM; i++)
	{
		midline[i] = { SCREEN_WIDTH / 2 - BOARDER_WIDTH / 2, i * BOARDER_WIDTH * 2 - 8,
						BOARDER_WIDTH, BOARDER_WIDTH };
	}
	SDL_RenderFillRects(rdr, midline, MID_NUM);

	// render game objects
	for (auto& obj : objs)
	{
		obj->draw(rdr);
	}

	SDL_RenderPresent(rdr);
}

Ball& Game::ball()
{
	return dynamic_cast<Ball&>(*objs[2]);
}

void Game::resetBall()
{
	ball().x = BALL_INIT_X;
	ball().y = BALL_INIT_Y;
	ball().vX = BALL_INIT_VX;
	ball().vY = BALL_INIT_VY;
}
