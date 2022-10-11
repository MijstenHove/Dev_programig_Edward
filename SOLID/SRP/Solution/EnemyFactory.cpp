#include "EnemyFactory.h"
#include "../Common/Enemy.h"
#include "../Common/Warrior.h"
#include "../Common/Archer.h"
#include <stdexcept>

Enemy* EnemyFactory::Create(EnemyTypes enemyType)
{
	switch (enemyType)
	{
		case EnemyTypes::Warrior:
			new Warrior();
			break;
		case EnemyTypes::Archer:
			new Archer();
			break;
	}	
	throw std::runtime_error("El tipo indicado no existe");
}
