#pragma once
#include <iostream>
#include <string>
class Renderer
{
protected:
	int x;
	int y;
//	std::string name;

public: 

	Renderer() ;

	Renderer(int a, int b) ;

	~Renderer() ;

	virtual void Draw();

};

