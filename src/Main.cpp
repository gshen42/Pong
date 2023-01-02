#include "Game.h"

int main(int argc, char* argv[]) {
	Game& g = Game::getInstance();
	g.run();

	return 0;
}