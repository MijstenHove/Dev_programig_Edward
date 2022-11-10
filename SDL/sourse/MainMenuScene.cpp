#include "MainMenuScene.h"
void  MainMenuScene::Update(float dt) {}

void MainMenuScene::Render(SDL_Renderer* renderer) {
// text data 
	//width
	//hight
	int width = 28 * sampleText.text.length();
	int hight = 50;
	//color 
	SDL_Color color = {0,0,0 };
	//surfaceS
	SDL_Surface* surface = TTF_RenderText_Solid(fond, sampleText.text.c_str(), color); 
	

	assert(surface != nullptr);


	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(texture != nullptr);

		SDL_SetTextureAlphaMod(texture, 255);

		SDL_Rect renderRect = { sampleText.position[0], sampleText.position[1], width, hight };

		// renderer , target texture, texture part, we want to draw,
		//where to draw en what size, angle, center of sprite , flip sprite 
		SDL_RenderCopyEx(renderer, texture, NULL, &renderRect, 0, NULL, SDL_FLIP_NONE);
}
	
void MainMenuScene::OnEnter() {

	if (TTF_Init() != -1)

		// load fond
	fond = TTF_OpenFont("resources/Fonds/hyperspace.ttf", 28);
	assert(fond != nullptr);
	sampleText.text = "hola";
}

void MainMenuScene::OnExit() {}
