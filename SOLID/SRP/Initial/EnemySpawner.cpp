#include "EnemySpawner.h"
#include "../Common/Warrior.h"
#include "../Common/Archer.h"
#include "../Common/EnemyTypes.h"
#include "../../Random.h"

EnemySpawner::EnemySpawner() : _timeToNextSpawn(0.0f)
{

}

void EnemySpawner::Init()
{
	CalculateTimeToNextSpawn();
}

void EnemySpawner::Update(float elapsedTime)
{
	_timeToNextSpawn -= elapsedTime;
	auto isReadyToSpawn = _timeToNextSpawn <= 0;
	if (!isReadyToSpawn)
	{
		return;
	}

	CalculateTimeToNextSpawn();
	SpawnRandomEnemy();
}


void EnemySpawner::CalculateTimeToNextSpawn()
{
	_timeToNextSpawn = Random::Range(2, 5);
}

void EnemySpawner::SpawnRandomEnemy()
{
	auto enemyToSpawn = GetRandomEnemyType();

	switch (enemyToSpawn)
	{
		case EnemyTypes::Warrior:
			new Warrior();
			break;
		case EnemyTypes::Archer:
			new Archer();
			break;
		default:
			break;
	}
}

EnemyTypes EnemySpawner::GetRandomEnemyType()
{
	return (EnemyTypes) Random::Range((int)EnemyTypes::Warrior, (int) EnemyTypes::Archer);
}
