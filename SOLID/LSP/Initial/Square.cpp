#include "Square.h"

Square::Square() : Rectangle()
{

}

void Square::SetSide(float side)
{
	_width = side;
	_height = side;
}