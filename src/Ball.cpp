#include "Ball.h"
#include "Common.h"
#include <cmath>

constexpr int BALL_SPEED = 15;

Ball::Ball(int x, int y, int r, int vX, int vY, GameObject* a, GameObject* b)
	: GameObject(x, y, r * 2, r * 2, vX, vY), playerA(a), playerB(b)
{
}

Ball::~Ball()
{
}

void Ball::draw(SDL_Renderer* rdr)
{
	SDL_SetRenderDrawColor(
		rdr,
		BALL_COLOR_R,
		BALL_COLOR_G,
		BALL_COLOR_B,
		BALL_COLOR_A
	);
	SDL_Rect r = { x, y, w, h };
	SDL_RenderFillRect(rdr, &r);
}

void Ball::update()
{
	// hitting the upper or lower walls
	if (y <= BOARDER_WIDTH || y >= SCREEN_HEIGHT - BOARDER_WIDTH - w)
	{
		vY = -vY;
	}

	// hitting the left side of playerA's racket
	if (x >= playerA->x - w && vX > 0 &&
		y >= playerA->y - w && y <= playerA->y + playerA->h)
	{

		int y_ball_center = y + h / 2;
		int y_player_center = playerA->y + playerA->h / 2;
		int y_max = h / 2 + playerA->h / 2;
		double radian = (y_ball_center - y_player_center) / static_cast<double>(y_max) * RADIAN_MAX;
		vX = BALL_SPEED * cos(abs(radian)) * -1;
		vY = BALL_SPEED * sin(radian);
	}

	// hitting the right side of playerB's racket
	if (x <= playerB->x + playerB->w && vX < 0 &&
		y >= playerB->y - w && y <= playerB->y + playerB->h)
	{
		int y_ball_center = y + h / 2;
		int y_player_center = playerB->y + playerB->h / 2;
		int y_max = h / 2 + playerB->h / 2;
		double radian = (y_ball_center - y_player_center) / static_cast<double>(y_max) * RADIAN_MAX;
		vX = BALL_SPEED * cos(abs(radian));
		vY = BALL_SPEED * sin(radian);
	}

	x += vX;
	y += vY;
}
