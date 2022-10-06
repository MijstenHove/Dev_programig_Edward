#pragma once
#include "Menu.h"
#include "Image.h"

class MainMenu : public Menu {
private:
	Image image;
public:
	
	virtual void Start() override {};
	virtual void DrawText() override {
		
		image.Draw();
		std::cout << " welcome to main menu" << std::endl;
		std::cout << "G- game" << std::endl;
		std::cout << "L- leaderbord" << std::endl;
		std::cout << "Q- quit \n" << std::endl;

		std::cout << "enter choice: " << std::endl;

	};
};
