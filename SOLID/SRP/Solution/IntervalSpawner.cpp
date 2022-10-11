#include "IntervalSpawner.h"
#include "../../Random.h"

IntervalSpawner::IntervalSpawner(std::function<void()> spawnCallback) 
	: _spawnCallback(spawnCallback), _timeToNextSpawn()
{
}

void IntervalSpawner::Init()
{
	CalculateTimeToNextSpawn();
}

void IntervalSpawner::Update(float elapsedTime)
{
	_timeToNextSpawn -= elapsedTime;
	auto isReadyToSpawn = _timeToNextSpawn <= 0;
	if (!isReadyToSpawn)
	{
		return;
	}

	CalculateTimeToNextSpawn();
	_spawnCallback();
}

void IntervalSpawner::CalculateTimeToNextSpawn()
{
	_timeToNextSpawn = Random::Range(2, 5);
}
