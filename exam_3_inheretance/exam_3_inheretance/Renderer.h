#pragma once
#include <string>
#include <vector>
#include<iostream>
class Renderer{
private:
public:
	bool FinishedDraw;

	Renderer() { FinishedDraw = false; };

	virtual	void Draw() = 0;

};




