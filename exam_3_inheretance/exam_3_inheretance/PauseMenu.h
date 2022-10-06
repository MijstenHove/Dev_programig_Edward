#pragma once
#include "Menu.h"
#include "Image.h"

class PauseMenu : public Menu {
private:
	Image image;
public:
	virtual void Start() override {};
	virtual void DrawText() override {
		image.Draw();
		std::cout << "game game " << std::endl;
		std::cout << "press B for menu " << std::endl;
	};
};

 