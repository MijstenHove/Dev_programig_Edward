//https://meet.google.com/ftk-ozme-abn
#include "Hero.h"
#include "Enemy.h"

int main() {
	Hero mijs(100,99);

	Character* pj = &mijs;
	((Hero*)pj)->Die();

	return 0;
};