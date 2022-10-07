#pragma once
#include"Menu.h"
#include"MainMenu.h"
#include"Leaderboard.h"
#include"PauseMenu.h"


#include <vector>
class MenuManager
{
public: 

	std::vector<Menu*> menus;

	void Draw() {};

///////////////////////////moet ergens anders heen///////////////
	virtual void Draw() {
		unsigned int currendScene = 0;
		bool isPlaying = true;

		MainMenu mainmenu;
		Leaderboard leaderbord;
		PauseMenu pausemenu;

		menus.push_back(&mainmenu);
		menus.push_back(&leaderbord);
		menus.push_back(&pausemenu);

		while (isPlaying) {
			//change scene?
			if (menus[currendScene]->menuFinished)
			{
				menus[currendScene]->End(currendScene, isPlaying);
				if (!isPlaying)
				{
					break;
				}
				menus[currendScene]->Start();
			};
			menus[currendScene]->DrawText();
			menus[currendScene]->Update();
		};


	}

};