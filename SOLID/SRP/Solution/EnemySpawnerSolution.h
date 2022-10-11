#pragma once
#include "EnemyFactory.h"
#include "IntervalSpawner.h"
#include "EnemySelector.h"

class EnemySpawnerSolution
{
public:
	EnemySpawnerSolution();
	void Update(float elapsedTime);



private:
	void SpawnRandomEnemy();
private:
	EnemyFactory _enemyFactory;
	EnemySelector _enemySelector;
	IntervalSpawner _intervalSpawner;

};

