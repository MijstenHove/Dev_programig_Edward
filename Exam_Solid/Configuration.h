#pragma once
class Configuration
{
public:
	Configuration(int _numberOfEnemies);
	int GetNumberOfEnemies();

	void SaveOnDisk(const Configuration& configuration);
private: 
	int _numberOfEnemies;
};

