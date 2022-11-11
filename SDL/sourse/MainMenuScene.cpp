#include "MainMenuScene.h"
void  MainMenuScene::Update(float dt) {
	//check if the mouse is inside the render rect 
	
	
	int width = 30 * sampleText.text.length();
	int hight = 50;
	

	int x = sampleText.position[0] - width / 2;
	int y = sampleText.position[1] - width / 2;

	int mouseX = IM->GetMousex();
	int mouseY = IM->GetMousey();

	//AABB Axes Alingd Bounding Box
	bool isinsideAABBX = mouseX > x && mouseX < x + width;
	bool isinsideAABBY = mouseY > y && mouseX < y + width;

	if (isinsideAABBX && isinsideAABBY){
		buttonAngle+= 0.1f;
		if (IM->CheckKayState(SDLK_j, PRESSED)) {
			SM->SetScene("splash screen");
			
		}
	}

	else
		buttonAngle = 0;
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
		SDL_RenderCopyEx(renderer, texture, NULL, &renderRect, sin(buttonAngle *(3.14f * 2.0f)/ 180.0f) * 10, NULL, SDL_FLIP_NONE);

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

	buttonAngle = 0;
}

void MainMenuScene::OnExit() {}
