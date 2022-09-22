#include <fstream>
#include <ios>
#include <istream>

#include <vector>
#include <list>
using namespace std;


	return 0;
	struct GameObject
	{
		char type;
		int x; 
		int y;

	};
	std::vector<GameObject> objecs;


	struct Weapon
	{
		char name[10];
		int power;
	};


	struct Enemy
	{
		char id;
		int c;
		float y;
		std::vector<Weapon> weapons;
	};
	std::list<Enemy> enemies;




void SaveObjects(std::vector<GameObject> o, std::string fileName) {


}

void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {


}