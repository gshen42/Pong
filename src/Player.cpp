#include "Player.h"
#include "Common.h"
#include "InputHandler.h"

Player::Player(int x, int y, int w, int h)
	: GameObject(x, y, w, h, 0, 0)
{
}

Player::~Player()
{
}

void Player::draw(SDL_Renderer* rdr)
{
	SDL_SetRenderDrawColor(
		rdr,
		PLAYER_COLOR_R,
		PLAYER_COLOR_G,
		PLAYER_COLOR_B,
		PLAYER_COLOR_A
	);
	SDL_Rect r = { x, y, w, h };
	SDL_RenderFillRect(rdr, &r);
}

void Player::update()
{
	auto y_offset = InputHandler::getInstance().yOffset();
	setY(y + y_offset);
	vY = y_offset;
}

void Player::setY(int y2)
{
	if (y2 + h > SCREEN_HEIGHT - BOARDER_WIDTH)
	{
		y = SCREEN_HEIGHT - BOARDER_WIDTH - h;
	}
	else if (y2 < BOARDER_WIDTH)
	{
		y = BOARDER_WIDTH;
	}
	else
	{
		y = y2;
	}
}