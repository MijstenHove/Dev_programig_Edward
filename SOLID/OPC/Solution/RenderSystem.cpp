#include "RenderSystem.h"
#include "Figure.h"

void RenderSystem::RenderFigure(const Figure* figure)
{
	figure->Render();
}
