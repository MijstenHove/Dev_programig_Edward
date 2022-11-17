#include "GameEngine.h"

GameEngine::GameEngine(int x, int y)
	: windowWidth(x), windowHeight(y), isRunning(true)
{
}
#pragma region INITIALIZATION
void GameEngine::Init() {
	InitSDL();
	InitWindowAndRenderer();
	//load still image
	SDL_Surface* surface = IMG_Load("resources/logo.png");
		assert(surface);

		SI_Texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(SI_Texture);

		SI_TargetRect = SDL_Rect{ 0,0,255,255};


		SDL_FreeSurface(surface);
		//load moving image 
		surface = IMG_Load("resources/spritesheet.png");
			assert(surface);

		MI_Texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(MI_Texture);
	
		MI_Rows = 9;
		MI_Cols = 17;
		MI_Frames = 9 * 17 - 3;
		MI_CurrentFrame = 0;
		MI_TargetRect = SDL_Rect{ -500,0,
			1000,
			1000};
		//MI_sourceRect = SDL_Rect{ frameX* width, frameX * width,588, 708 };
		MI_sourceRect = SDL_Rect{ 0,0,
			surface->w / MI_Cols, 
			surface->h / MI_Rows };
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
	while (!quit) {

		SDL_Event e;
		while (SDL_PollEvent(&e) != 0);
		{
			quit = e.type == SDL_QUIT;
		}

		float Deltatime;
		Deltatime = (float)(SDL_GetPerformanceCounter() - MI_LastGameTime) / SDL_GetPerformanceFrequency();
		MI_LastGameTime = SDL_GetPerformanceCounter();
		std::cout << Deltatime << std::endl;
	// clear screen
		SDL_RenderClear(renderer);
		//render still image 
		SDL_RenderCopy(renderer, SI_Texture, NULL, &SI_TargetRect);
		// upadte moving img
		MI_CurrentFrameTime += Deltatime;
		int frameIncrement = (int)(MI_CurrentFrameTime / MI_MaxFrameTime);

		MI_CurrentFrameTime = ((MI_CurrentFrameTime / MI_MaxFrameTime) - (float)frameIncrement)* MI_MaxFrameTime;
		MI_CurrentFrame = (MI_CurrentFrame + frameIncrement) % MI_Frames;
		int frameX = MI_CurrentFrame % MI_Cols;
		int frameY = MI_CurrentFrame / MI_Cols;

		

		MI_sourceRect = { MI_sourceRect.w * frameX,
			MI_sourceRect.h * frameY,
			MI_sourceRect.w,
			MI_sourceRect.h
		};

		//render moving img 
		SDL_RenderCopy(renderer, MI_Texture, &MI_sourceRect, &MI_TargetRect);
		//render screen
		SDL_RenderPresent(renderer);
	}

}


