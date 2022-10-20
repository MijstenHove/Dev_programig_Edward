#include "Gameobject.h"

void Gameobject::LoadTecture(SDL_Renderer* renderer, std::string path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_QueryTexture(texture,nullptr,nullptr,&sourcerect.w, &sourcerect.h);
	
	// free the surface 
	SDL_FreeSurface(surface);


	//update the destonation rect 
	destanationRect.w = sourcerect.w;
	destanationRect.h = sourcerect.h;

}

void Gameobject::SetPosition(int x, int y) {
	destanationRect.x = x;
	destanationRect.y= y;

}