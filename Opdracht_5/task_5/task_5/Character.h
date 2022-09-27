#pragma once


class Character {
public:

	int hp;
	Character(int hp) { this->hp = 100; }
	void attack() {};
	void ReciveDamage(int damage) {
		hp -= damage;
	}

	virtual void Move() {};
	virtual void Die() = 0;
	//~Character();


};