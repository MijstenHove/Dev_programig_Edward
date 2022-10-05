#pragma once
#include "RenderMenager.h"

class Animation2D : public RenderMenager {
public:
	virtual void Draw() override {
		std::cout << "animation" << std::endl;
	}

private:
	int xpos = 0;
	int ypos = 0; 
};

