#include "AI.h"

AI::AI(int x, int y, int w, int h, GameObject* ball)
    : Player(x, y, w, h), ball(ball)
{
}

void AI::update()
{
    setY(ball->y - h / 2);
}

void AI::trackBall(GameObject* ball)
{
    this->ball = ball;
}
