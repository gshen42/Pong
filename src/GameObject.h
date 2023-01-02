#pragma once
#include <SDL.h>

/**
* A general interface that all game objects implment.
*/
class GameObject
{
public:
	GameObject(int x, int y, int w, int h, int vX, int vY);
	virtual ~GameObject();
	virtual void draw(SDL_Renderer*) = 0;
	virtual void update() = 0;

	int x, y, w, h;
	int vX, vY;
};
