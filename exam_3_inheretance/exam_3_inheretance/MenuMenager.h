#pragma once
#include <iostream>
class MenuMenager
{
private:
	char choice;
public:
	bool menuFinished;
	MenuMenager() { menuFinished = false; };
	virtual void Start() = 0;
	virtual void Update() {
		std::cin >> choice;
		if (choice == 'm' || choice == 'l' || choice == 'q' || choice == 'g' )
		{
			menuFinished = true;
		}
	
	};
	virtual void DrawText() = 0;
	virtual void End(unsigned int& targetscene, bool& keepPlaying){
		switch (choice)
		{
		case 'm':
			//main
			targetscene = 0;
			break;
		case 'l':
			//leaderbord
			targetscene = 1;
			break;
		case 'q':
			//quit 
			keepPlaying = false;
			break;
		case 'g':
			//Game 
			targetscene = 2;
			break;
		case 'p':
			//pause
			targetscene = 3;
			break;
		};
}


private:


};

