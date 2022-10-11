#include "Rectangle.h"

Rectangle::Rectangle() : _width(0), _height(0)
{
}

float Rectangle::GetArea()
{
	return _width * _height;
}

void Rectangle::SetWidth(float width)
{
	_width = width;
}

float Rectangle::GetWidth()
{
	return _width;
}

void Rectangle::SetHeight(float height)
{
	_height = height;
}

float Rectangle::GetHeight()
{
	return _height;
}
