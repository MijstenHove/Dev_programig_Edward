#pragma once
#include "Renderer.h"
class Model3D: Renderer
{
public:
	Model3D();
	Model3D(int a, int b);
	~Model3D();

	virtual void Draw() override;


};

