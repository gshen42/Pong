#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(int x, int y, int r, int vX, int vY, GameObject* a, GameObject* b);
	~Ball() override;
	void draw(SDL_Renderer*) override;
	void update() override;

private:
	GameObject* playerA; // on the right side of the screen
	GameObject* playerB; // on the left side of the screen
};
