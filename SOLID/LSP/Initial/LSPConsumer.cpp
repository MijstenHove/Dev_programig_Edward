#include "LSPConsumer.h"
#include "Square.h"
#include "Rectangle.h"
#include <cstdio>

void LSPConsumer::SetWidthTo4(Rectangle& rectangle)
{
    rectangle.SetWidth(4);
}

void LSPConsumer::Main()
{
	Square square = Square();

    std::printf("width: %f height: %f\n", square.GetWidth(), square.GetHeight());

    square.SetSide(2); // ambos lados son seteados a 2
    std::printf("width: %f height: %f\n", square.GetWidth(), square.GetHeight());

    square.SetSide(3); // ambos lados son seteados a 3
    std::printf("width: %f height: %f\n", square.GetWidth(), square.GetHeight());

    SetWidthTo4(square);
    std::printf("width: %f height: %f\n", square.GetWidth(), square.GetHeight());

    // Además podemos hacer square.SetWidth(10) y solo afectar a un lado
}