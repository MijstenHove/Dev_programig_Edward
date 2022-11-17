#include "GameEngine.h"

int main(int argc, char* args[]) {
	GameEngine game(700, 700);
	game.Init();
	game.Run();
	game.Quit();
	return 0;
}




