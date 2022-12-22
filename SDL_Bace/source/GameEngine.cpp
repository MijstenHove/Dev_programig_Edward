#include "GameEngine.h"

GameEngine::GameEngine(int x, int y)
	: windowWidth(x), windowHeight(y), isRunning(true)
{
	R = new Inerpolator(3.f);
	G = new Inerpolator(3.f);
	B = new Inerpolator(1.f);
}
#pragma region INITIALIZATION
void GameEngine::Init() {

	InitSDL();
	InitWindowAndRenderer();

	//audio
	AudioManager::GetInstance()->LoadSFX("shrek");
	AudioManager::GetInstance()->LoadMusic("helicopter");

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
	AM->UnLoadSFX("shrek");
	AM->UnLoadMusic("helicopter");
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Game loop
void GameEngine::Run() {
	while (!IM->GetQuitEvent()) {
		IM->Listen();


		if (R->IsMinPrecise()) {
			std::cout << R->GetValue() << std::endl;
			R->ToMax();
		}
		else if (R->IsMaxPrecise()) {
			R->ToMin();
		}

		if (IM->CheckKeyState(SDLK_g, PRESSED))
			G->ToMax();
		else
			G->ToMin();
		if (IM->CheckKeyState(SDLK_b, PRESSED))
			B->ToMax();
		else
			B->ToMin();



		//____________________________________
		R->Update(0.001f);
		G->Update(0.001f);
		B->Update(0.001f);

		SDL_SetRenderDrawColor(renderer,
			(int)(R->GetValue() * 255.f),
			(int)(G->GetValue() * 255.f),
			(int)(B->GetValue() * 255.f),
			255);

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);


		while (!IM->GetQuitEvent())
		{
			IM->Listen();

			if (IM->CheckKeyState(SDLK_SPACE,DOWN)) {
				AudioManager::GetInstance()->PlaySFX("shrik", 1);
			
			}
		}
	}
}
