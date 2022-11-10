#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashScreenScene.h"
#include "MainMenuScene.h"

class GameEngine
{
private: 
	//------EXECUTE CONTROL
	bool isRunning;

	//------ SDL
	SDL_Window* window;
	SDL_Renderer* renderer;

	int windowWidth;
	int windowHeight;

	void InitSDL();
	void InitWindowAndRenderer();

	//------EVENTS
	void HandelEvents();
	InputManager im; 
	//-------RENDEr
	void Render();

	Gameobject logo;
public:
	GameEngine(int x, int y);
	// init = start is spain
	void Init();
	void Run();
	void Quit();
	

	void Test() {
		SceneManager::GetInstance();
		//SM;
	}
};

