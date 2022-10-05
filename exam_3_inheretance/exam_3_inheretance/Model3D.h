#pragma once
#include "RenderMenager.h"
class Model3D : public RenderMenager
{
private:
public:

	virtual void Draw() override {
		std::cout << "model" << std::endl;
	}
};

