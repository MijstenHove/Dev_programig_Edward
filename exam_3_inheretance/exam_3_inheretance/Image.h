#pragma once
#include "RenderMenager.h"
class Image : public RenderMenager
{
private:
public:
	virtual void Draw() override {
		std::cout << "logo" << std::endl;
	}
};
