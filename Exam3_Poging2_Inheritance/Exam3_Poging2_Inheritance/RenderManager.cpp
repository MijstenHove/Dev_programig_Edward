#include "RenderManager.h"
#include <ostream>
#include <iostream>

void RenderManager::Draw()
{
	for (int i = 0; i < renderers.size(); i++)
	{
		renderers[i].Draw();
	}

};