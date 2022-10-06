#pragma once
#include "Renderer.h"
#include "Animation2D.h"
#include "Image.h"
#include "Model3D.h"

#include <vector>
class RenderMenager {
public:
	//what is the differense between this one ande the renderer? 
	virtual void Draw() {
		Image image;
		Animation2D animation2d;
		Model3D model3d;

		std::vector<Renderer*> renderers;
		renderers.push_back(&image);
		renderers.push_back(&animation2d);
		renderers.push_back(&model3d);
	

		for (int i = 0; i < renderers.size(); i++)
		{
			renderers[i]->Draw();
		}

	};
};

