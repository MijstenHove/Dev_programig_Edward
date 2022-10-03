#pragma once
#include "RenderMenager.h"
class Model3D : public RenderMenager
{
public:
	virtual void Text() override {
		object.push_back({ "model 3D" });
	}
};

