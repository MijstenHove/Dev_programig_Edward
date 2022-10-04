#pragma once
#include "MenuMenager.h"

class MainMenu : public MenuMenager {
private:
public:
	MainMenu()
		:MenuMenager() {
		menuFinished = false;
	};

	virtual void Start() override {};
	virtual void DrawText() override {
		std::cout << " welcome to main menu" << std::endl;
		std::cout << "G- game" << std::endl;
		std::cout << "L- leaderbord" << std::endl;
		std::cout << "Q- quit \n" << std::endl;

		std::cout << "enter choice: " << std::endl;

	};
};
