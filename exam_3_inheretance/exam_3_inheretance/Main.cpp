
#include"MenuMenager.h"
#include"MainMenu.h"
#include"Leaderboard.h"
#include"PauseMenu.h"
#include "RenderMenager.h"
#include<vector>

int main() {
	unsigned int currendScene = 0;
	bool isPlaying = true;

	MainMenu mainmenu;
	Leaderboard leaderbord;
	PauseMenu pausemenu;

	std::vector<MenuMenager*> menumenager;
	menumenager.push_back(&mainmenu);
	menumenager.push_back(&leaderbord);
	menumenager.push_back(&pausemenu);

	while (isPlaying) {
		//change scene?
		if (menumenager[currendScene]->menuFinished)
		{
			menumenager[currendScene]->End(currendScene, isPlaying);
			if (!isPlaying)
			{
				break;
			}
			menumenager[currendScene]->Start();
		};
		menumenager[currendScene]->DrawText();
		menumenager[currendScene]->Update();
	};
	return 0;

}
