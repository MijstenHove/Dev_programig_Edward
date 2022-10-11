#pragma once

#include "Rectangle.h"
class Square
{
public:
	Square();

	float GetArea();

	void SetWidth(float width);
	float GetWidth();
	void SetHeight(float height);
	float GetHeight();
private:
	float _width;
	float _height;
};