#pragma once
#include <unordered_map>
#include <SDL.h>
enum KayState{
UNDEFINED = 1,    //code tries to scces kay but it hasn't been regigstered yet 
DOWN = 2,        //frame kay is pressed
PRESSED = 4,    // the kay is pressed 
UP = 8,        //frame kay is released
RELEASED = 16 //released
};
class InputManager
{
private:
	std::unordered_map<int32_t, KayState> kays;
	int mousex, mousey;
	bool quitEvent
public:
	InputManager() :quitEvent(false), mousex(0), mousey(0);
	void Listen();
	bool CheckKayState(Sint32 kay, KayState state);
	int GetMousex();
	int GetMousey();
	int GetQuit();
};

