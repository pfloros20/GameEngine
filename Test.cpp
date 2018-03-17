#include "SDL.h"
#include "Game.h"
int main(int argc, char *args[]) {
	
	Game game = Game("title",600,400);
	while (game.State()) {
		game.HandleEvents();
		//game.Update();
		game.Render();
	}
	return 0;
}