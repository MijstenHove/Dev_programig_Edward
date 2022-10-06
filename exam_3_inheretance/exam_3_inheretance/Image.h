#pragma once
#include "Renderer.h"
class Image : public Renderer{
private:
public:
	virtual void Draw() override {
		std::cout << "logo" << std::endl;
	}
};
