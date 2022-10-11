#include "EnemySpawnerSolution.h"
#include <functional>

EnemySpawnerSolution::EnemySpawnerSolution() :
	_enemyFactory(),
	_enemySelector(),
	_intervalSpawner(std::bind(&EnemySpawnerSolution::SpawnRandomEnemy, this))
{
}

void EnemySpawnerSolution::Update(float elapsedTime)
{
	_intervalSpawner.Update(elapsedTime);
}

void EnemySpawnerSolution::SpawnRandomEnemy()
{
	auto enemyTypeToSpawn = _enemySelector.Select();
	auto enemy = _enemyFactory.Create(enemyTypeToSpawn);
}
