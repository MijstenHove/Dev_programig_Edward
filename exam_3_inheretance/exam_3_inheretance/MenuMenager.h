#pragma once
#include <iostream>
#include "RenderMenager.h"
class MenuMenager
{
public:
	bool menuFinished;
	char choice;
	MenuMenager() { menuFinished = false; };
	virtual void Start() = 0;
	virtual void Update() {

			std::cin >> choice;
			if (choice == 'g' || choice == 'l' || choice == 'q' || choice == 'b')
			{
				menuFinished = true;
			}
	};
	virtual void DrawText() = 0;
	virtual void End(unsigned int& targetScene, bool& keepplaying){
		switch (choice)
		{
		case 'b':
			targetScene = 0;
			break;
		case 'l':
			targetScene = 1;
			break;
		case 'g':
			targetScene = 2;
			break;
		case 'q':
			keepplaying = false;
			break;
		}
	}
};
