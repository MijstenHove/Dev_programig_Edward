#pragma once
#include "../Common/EnemyTypes.h"

class Enemy;
class EnemyFactory
{
public:
	Enemy* Create(EnemyTypes enemyType);
};

