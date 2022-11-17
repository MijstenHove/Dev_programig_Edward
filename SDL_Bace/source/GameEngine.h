#pragma once
#include <SDL.h>
#include "InputManager.h"

class GameEngine {
private:
	//------ EXECUTION CONTROL
	bool isRunning;
	
	//------ SDL
	SDL_Window* window;
	SDL_Renderer* renderer;

	int windowWidth;
	int windowHeight;

	void InitSDL();
	void InitWindowAndRenderer();

	//------ RENDER
	void Render();

public:
	GameEngine(int x, int y);

	void Init();
	void Run();
	void Quit();
};
