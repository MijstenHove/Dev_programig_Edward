#pragma once
#include <string>
#include <vector>
#include<iostream>
class RenderMenager
{
private:
public:
	bool FinishedDraw;

	RenderMenager() { FinishedDraw = false; };

	virtual	void Draw() = 0;

};




