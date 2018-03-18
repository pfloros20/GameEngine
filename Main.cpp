#include "SDL.h"
#include "Game.h"
#include <iostream>
int main(int argc, char *args[]) {
	{
		Game game = Game();


		while (game.State()) {
			game.HandleEvents();
			game.Update();
			game.Render();
			SDL_Delay(17);
		}
	}
	_CrtDumpMemoryLeaks();
	std::cin.get();
	return 0;
}