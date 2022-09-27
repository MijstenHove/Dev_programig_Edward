#pragma once
#include "Character.h"

class Enemy : public Character {
public:
	virtual void Move() override {
		hp-= 10;
	}
};

