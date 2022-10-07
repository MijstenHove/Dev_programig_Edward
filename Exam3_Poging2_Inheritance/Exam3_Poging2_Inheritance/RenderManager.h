#pragma once
#include "Renderer.h"
#include <vector>

class RenderManager
{
public:

	std::vector<Renderer> renderers;
	virtual void Draw();


};

