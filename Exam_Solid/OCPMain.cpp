#include "OCPMain.h"

void OCPMain::Main() {
	auto enemy = Enemy(false);
	auto boss = Enemy(true);
	auto enemies = std::vector<Enemy>{ enemy,boss };

	PrintEnemiesHelth(enemies);
}

void  OCPMain::PrintEnemiesHelth(const std::vector<Enemy> &enemies) {
	for (auto enemy : enemies)	{
		if (enemy.IsBoss()) {
			std::printf("is boss\n", 200);
		}
		else if (!enemy.IsBoss()) {
			std::printf("is not a boss\n", 100);
		}
	}

}