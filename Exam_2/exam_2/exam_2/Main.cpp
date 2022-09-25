#include<fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <list>
using namespace std;


	
	struct GameObject{
		char type;
		int x; 
		int y;

	};
	std::vector<GameObject> objecs;


	struct Weapon{
		char name[10];
		int power;
	};


	struct Enemy{
		char id;
		int c;
		float y;
		std::vector<Weapon> weapons;
	};
	std::list<Enemy> enemies;


	int main() {
//writing the file ard coded
		Weapon weapon = { "big ax", 50 };

		fstream f;
		f.open("save.dat", ios::out | ios::binary);

		if (f.is_open())
		{
			f.write(reinterpret_cast<char*>(&weapon), sizeof(Weapon));
			f.close();
		}
		else
		{
			std::cout << "error: \n";
		}
	
		//reading the file
		Weapon newWeapon;
		f.open("save.dat", ios::out | ios::binary);

		if (f.is_open())
		{
			f.read(reinterpret_cast<char*>(&newWeapon), sizeof(Weapon));
			f.close();
		}
		else
		{
			std::cout << "error: \n";
		}

		cout << weapon.name << endl;
		cout << newWeapon.power << endl;



	}


void SaveObjects(std::vector<GameObject> o, std::string fileName) {


}

void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {


}