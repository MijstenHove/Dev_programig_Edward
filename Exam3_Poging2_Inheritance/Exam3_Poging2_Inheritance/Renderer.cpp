#include "Renderer.h"

Renderer::Renderer()
{
};

Renderer::Renderer(int a, int b)
{
	y = a;
	x = b;
};

Renderer::~Renderer()
{
};

void Renderer::Draw()
{
   std::cout << " posX: " << x << " PosY: " << y << std::endl;
};