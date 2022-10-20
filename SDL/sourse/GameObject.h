#pragma
#include<SDL.h>
#include <string>
#include <SDL_image.h>
class Gameobject
{
private:

public:
	SDL_Texture* texture;
	SDL_Rect destanationRect;
	SDL_Rect sourcerect;


	Gameobject() = default;
	void LoadTecture(SDL_Renderer* renderer, std::string path);
	void SetPosition(int x, int y);

};