#pragma once
#include "Renderer.h"
#include "MenuManager.h"
#include <iostream>
#include <vector>
class Menu
{
public:
	// doos this need the rendermanager to? 
	std::vector<Renderer> renderers;
	virtual void Start() = 0; 
	virtual void Draw();
	virtual void End(unsigned int& targetScene, bool& keepplaying) = 0;
};

