#pragma once
#include "MenuMenager.h"

class MainMenu : public MenuMenager {
private:
	//char choice;
public:
	virtual void Start() override {};
	virtual void Update();
	virtual void DrawText() override {
		std::cout << " welcome to main menu\n\n" << std::endl;
		std::cout << "G- game" << std::endl;
		std::cout << "L- leaderbord" << std::endl;
		std::cout << "Q- quit \n" << std::endl;

		std::cout << "enter choice: " << std::endl;

	};
	virtual void End(unsigned int& targetScene, bool& keepplaying) override {};


};
