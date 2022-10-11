#pragma once
#include "EnemySpawner.h"
enum class EnemyTypes;

class EnemySpawner
{
public:
	EnemySpawner();
	void Init();

	void Update(float elapsedTime);

private:
	void CalculateTimeToNextSpawn();
	void SpawnRandomEnemy();
	EnemyTypes GetRandomEnemyType();

private:
	float _timeToNextSpawn;
};

