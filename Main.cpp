#include "SDL.h"
#include "Game.h"
#include <iostream>
int main(int argc, char *args[]) {
	{
		Game game;


		while (game.State()) {
			game.HandleEvents();
			game.Update();
			game.Render();
		}
	}
	_CrtDumpMemoryLeaks();
	std::cin.get();
	return 0;
}