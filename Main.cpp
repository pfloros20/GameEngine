#include "SDL.h"
#include "Game.h"
int main(int argc, char *args[]) {
	
	Game game = Game("Moving Character",600,400);
	

	while (game.State()) {
		game.HandleEvents();
		game.Update();
		game.Render();
		SDL_Delay(33);
	}
	return 0;
}