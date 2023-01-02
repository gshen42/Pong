#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(int x, int y, int w, int h);
	~Player() override;
	void draw(SDL_Renderer*) override;
	void update() override;

protected:
	void setY(int);
};
