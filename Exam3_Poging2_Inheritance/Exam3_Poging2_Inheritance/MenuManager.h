#pragma once
#include <vector>
#include "Menu.h"
class MenuManager
{
public:
	int currentMenu = 0;
	std::vector<Menu> menus;
	void Draw() {
		//menus[currentMenu].Draw();
	}
};

