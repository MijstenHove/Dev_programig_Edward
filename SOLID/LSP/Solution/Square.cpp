#include "Square.h"
#include "Area.h"

Square::Square() : _width(), _height()
{

}

float Square::GetArea()
{
	return Area::Rectangle(_width, _height);
}
void Square::SetWidth(float width)
{
	_width = width;
	_height = width;
}

float Square::GetWidth()
{
	return _width;
}

void Square::SetHeight(float height)
{
	_width = height;
	_height = height;
}

float Square::GetHeight()
{
	return _height;
}
