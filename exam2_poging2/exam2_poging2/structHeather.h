#pragma once
#include <vector>
struct GameObject {
	char type;
	int x;
	int y;
};

struct Weapen {
	char name[10];
	int power;
};

struct Enemy
{
	char id;
	int x;
	float y;
	std::vector<Weapen> weapon;
};