#pragma once
#include <functional>
class IntervalSpawner
{
public:
	IntervalSpawner(std::function<void()> spawnCallback);
	void Init();
	void Update(float elapsedTime);
private:
	void CalculateTimeToNextSpawn();

private:
	float _timeToNextSpawn;
	std::function<void()> _spawnCallback;
};

