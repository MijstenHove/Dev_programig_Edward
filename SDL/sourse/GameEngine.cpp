#include "GameEngine.h"
#include <random>

GameEngine::GameEngine(int x, int y)
	: windowHeight(x), windowWidth(y), isRunning(true)
{	
	//same as above
	//windowHeight = x;
	//windowWidth = y;
}
#pragma region INITIALIZATION
void GameEngine::Init() 
{
	InitSDL();
	 
	InitWindowAndRenderer();

	logo.LoadTecture(renderer, "resources/logo.png");
}

void GameEngine::InitSDL() {

	// ensures that sdl is working and it can runn
	int result = SDL_Init(SDL_INIT_VIDEO);

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();


}
void GameEngine::InitWindowAndRenderer() {

	//create a window and a renderer
	int result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer);
	
	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();


}

//void GameEngine::Quit() {
//	//destroys all windows en renderers and than quits
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//
//
//}
#pragma endregion 

void GameEngine::Quit() {
	//destroys all windows en renderers and than quits
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


}

void GameEngine::Run() {
	//befor game loop
	{
		SM->AddScene("Splach screen", new SplashScreenScene());
		SM->AddScene("main Menu", new MainMenuScene());
		SM->SetScene("main Menu");
	}
	
	//game loop
	while (isRunning){
		IM->Listen();
		isRunning = !IM->GetQuitEvent();
		SM->GetCurrentScene()->Update(0.0f);
		//renderer
		SDL_SetRenderDrawColor(renderer, 100, 0, 0, 225);
		SDL_RenderClear(renderer);
		SM->GetCurrentScene()->Render(renderer);
		SDL_RenderPresent(renderer);
		//Render();
	}
}

// word niet meer gebruikt 
void GameEngine::HandelEvents() {
	SDL_Event evt;

	while(SDL_PollEvent(&evt)) {
		if (evt.type == SDL_QUIT)
			isRunning = false;
		//isRunning = !(evt.type == SDL_QUIT); same as above
	
	}
}

void GameEngine::Render() {
//
// set color background
	SDL_SetRenderDrawColor(renderer, rand() % 255 + 0, 0, 0, 225);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, logo.texture, &logo.sourcerect, &logo.destanationRect);
	
	//clear somting sould be last line 
	SDL_RenderPresent(renderer);
// gameobjecs

// UI
 

}
