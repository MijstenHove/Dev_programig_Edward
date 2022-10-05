#pragma once
#include "MenuMenager.h"
#include "Image.h"

class MainMenu : public MenuMenager {
private:
	Image image;
public:
	
	virtual void Start() override {};
	virtual void DrawText() override {
		//
		image.Draw();
		std::cout << " welcome to main menu" << std::endl;
		std::cout << "G- game" << std::endl;
		std::cout << "L- leaderbord" << std::endl;
		std::cout << "Q- quit \n" << std::endl;

		std::cout << "enter choice: " << std::endl;

	};
};
