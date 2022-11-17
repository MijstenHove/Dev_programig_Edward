#include "GameEngine.h"

GameEngine::GameEngine(int x, int y)
	: windowWidth(x), windowHeight(y), isRunning(true)
{
}
#pragma region INITIALIZATION
void GameEngine::Init() {
	InitSDL();
	InitWindowAndRenderer();
}

//Ensures that SDL is working and it can run
void GameEngine::InitSDL() {
	//Load SDL and check if it is correct
	int result = SDL_Init(SDL_INIT_VIDEO);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}
//Create the SDL window and renderer
void GameEngine::InitWindowAndRenderer() {

	int result = SDL_CreateWindowAndRenderer(
		windowWidth, windowHeight,
		SDL_WINDOW_SHOWN,
		&window,
		&renderer);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}
#pragma endregion

//Destroys all windows and renderers adn the quits SDL
void GameEngine::Quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Game loop
void GameEngine::Run() {
}


