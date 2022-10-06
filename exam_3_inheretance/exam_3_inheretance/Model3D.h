#pragma once
#include "Renderer.h"
class Model3D : public Renderer{
private:
public:

	virtual void Draw() override {
		std::cout << "model" << std::endl;
	}
};

