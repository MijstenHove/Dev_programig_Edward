#pragma once
#include "Renderer.h"

class Animation2D : public Renderer {
private:
	int xpos = 0;
	int ypos = 0;
public:
	virtual void Draw() override {
		std::cout << "animation" << std::endl;
	}
};

