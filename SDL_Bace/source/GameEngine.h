#pragma once
#include <SDL.h>
#include "InputManager.h"
#include <cassert>
#include <SDL_image.h>
#include <iostream>
#include "../Inerpolator.h"

#include "AudioManager.h"
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

	Inerpolator* R;
	Inerpolator* G;
	Inerpolator* B;

	
	//--------------- still image 
	SDL_Texture* SI_Texture;
	SDL_Rect SI_TargetRect;

	//---------------- moving image 
	SDL_Texture* MI_Texture;
	SDL_Rect MI_TargetRect;
	SDL_Rect MI_sourceRect;
	int MI_FRameWith, MI_Frameheight;
	int MI_Rows, MI_Cols, MI_Frames, MI_CurrentFrame;
	float MI_LastGameTime = 0.0f,
		MI_CurrentFrameTime = 1.f, 
		MI_MaxFrameTime = 1.f/10.f;


	bool quit = false; 

public:
	GameEngine(int x, int y);

	void Init();
	void Run();
	void Quit();
};
