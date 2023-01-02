#pragma once
#include "Player.h"

class AI : public Player
{
public:
	AI(int x, int y, int w, int h, GameObject* ball = nullptr);
	void update() override;
	void trackBall(GameObject* ball);

protected:
	GameObject* ball;
};
