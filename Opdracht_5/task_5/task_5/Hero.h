#pragma once
#include "Character.h"

class Hero : public Character {
public:
	Hero(int hp, int fame)
	:Character(hp){
		this->hp += 50;
		this->fame += fame;
	}
	int fame;
	virtual void Move() override {
		hp--;
	}
	virtual void Die() override {
	//die code 
		int a = 0;
	}

};
