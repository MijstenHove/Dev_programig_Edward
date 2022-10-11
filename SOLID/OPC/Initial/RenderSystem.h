#pragma once
class Square;
class Triangle;

class RenderSystem
{
public:
	void RenderSquare(const Square *square);
	void RenderTriangle(const Triangle *triange);
};