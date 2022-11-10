#include "MainMenuScene.h"
void  MainMenuScene::Update(float dt) {



}

void MainMenuScene::Render(SDL_Renderer* renderer) {
// text data 
	//width
	//hight
	int width = 30* sampleText.text.length();
	int hight = 50;
	//color of text 
	SDL_Color color = {255,0,0 };
	//surfaceS
	SDL_Surface* surface = TTF_RenderText_Solid(fond, sampleText.text.c_str(), color); 
	

	assert(surface != nullptr);


	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(texture != nullptr);

		SDL_SetTextureAlphaMod(texture, 255);

		SDL_Rect renderRect = { sampleText.position[0] - width / 2,
			sampleText.position[1] - hight / 2,
			width, 
			hight };

		// renderer , target texture, texture part, we want to draw,
		//where to draw en what size, angle, center of sprite , flip sprite 
		SDL_RenderCopyEx(renderer, texture, NULL, &renderRect, 0, NULL, SDL_FLIP_NONE);

		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);

}
	
void MainMenuScene::OnEnter() {

	if (TTF_Init() != -1)

		// load fond
	fond = TTF_OpenFont("resources/Fonds/hyperspace.ttf", 28);
	assert(fond != nullptr);
	sampleText.text = "hola! "; 
	sampleText.position[0] = 250;
	sampleText.position[1] = 250;
}

void MainMenuScene::OnExit() {}
