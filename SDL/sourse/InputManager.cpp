#include "InputManager.h"


void InputManager::Listen() {
	//hacer update de los eventos acutales
	for (auto i = kays.begin(); i != kays.end(); i++) {
		
		if ((i->second & DOWN) > 0) {
			i->second = PRESSED;
		}
		else if ((i->second & UP) > 0) {
			i->second = RELEASED;
		}
	}
	
	//process SDL and save events in a COLA
	//mouse
	//SDL_GETMouseSTATE(&mousex, &mouseY);

	SDL_Event evt; 

	while (SDL_PollEvent(&evt)){
		if (evt.type ==SDL_QUIT) {
			quitEvent = true;
		}
else if (evt.type == SDL_KEYDOWN){
			kays[evt.key.keysym.sym] = (KayState)(DOWN | PRESSED);
		}
		else if (evt.type = SDL_KEYUP) {
			kays[evt.key.keysym.sym] = (KayState)(UP | RELEASED);
		}
	}
}


bool InputManager::CheckKayState(Sint32 kay, KayState state) {
	if (kays.find(kay)!= kays.end()){
		// check if state == value
		return ((int)kays[kay] == state & (int)state)>0;
	}
	else{
		 //create kay with undefinded value
		kays.emplace(kay, UNDEFINED);
		return (state & UNDEFINED)> 0;
	}
}

int InputManager::GetMousex() 
{
	return mousex;
}
int InputManager::GetMousey()
{
	return mousey;
}

int InputManager::GetQuit()
{
	return quitEvent;
}
