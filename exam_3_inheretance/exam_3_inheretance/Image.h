#pragma once
#include "RenderMenager.h"
class Image : public RenderMenager
{
public:
	virtual void Text() override {
		object.push_back({ "image" });
	}
};

