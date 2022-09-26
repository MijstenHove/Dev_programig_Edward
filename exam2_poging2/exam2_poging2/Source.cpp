#include<fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


// to create random numbers 
#include <cstdalign>
#include<time.h>

struct GameObject{
	char type;
	int x;
	int y;
};

struct Weapen{
	char name[10];
	int power;
};

struct Enemy 
{
	char id;
	int x;
	float y;
	std::vector<Weapen> weapon;
};


void SaveObjects(std::vector<GameObject> o, std::string fileName);
void RecoverObjects(std::vector<GameObject>& o, std::string fileName);

void SaveEnemies(std::list<Enemy> e, std::string fileName);
void RecoverEnemies(std::list<Enemy>& e, std::string fileName);

void SaveMap(std::map<std::string, int> m, std::string fileName);
void RecoverMap(std::map<std::string, int>& m, std::string bestandsnaam);

int main() {
	string savefile = "save.dat";

	std::vector<GameObject> objecs;
	objecs.push_back({ 'a',23, 6 });
	objecs.push_back({ 'b',22, 5 });
	objecs.push_back({ 'c',13, 5 });

	SaveObjects(objecs, savefile);
	RecoverObjects(objecs, savefile);


	std::list<Enemy> enemies = {
		{'a',2,4,{{"knife",2},{"ax",5}}},
		{'b',2,4,{{"ax",2},{"ax",5}}},
		{'c',2,4,{{"bow",6},{"knife",5}}}
	};
	

	SaveEnemies(enemies, savefile);
	RecoverEnemies(enemies, savefile);

	std::map<std::string, int> myMap = {
		{"player", 1},
		{"enemy1", 1},
		{"enemy2", 1},
	};
	SaveMap(myMap, savefile);
	RecoverMap(myMap, savefile);


 return 0;
}

void SaveObjects(std::vector<GameObject> o, std::string fileName) {
	fstream f;

	f.open(fileName, ios::out | ios::binary | std::ios::trunc);
	f.write(reinterpret_cast<char*>(&o), sizeof(o));
	f.close();

	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;
		f.close();
	}

}

void RecoverObjects(std::vector<GameObject> &o, std::string fileName) {
	fstream f;

	f.open(fileName, ios::in | ios::binary | std::ios::trunc);
	f.read(reinterpret_cast<char*>(&o), sizeof(o));
	f.close();


	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;

		f.close();
	}

	for (GameObject gm : o){
		std::cout << gm.type << endl;
		std::cout << gm.x << endl;
		std::cout << gm.y << endl;
	}
}


void SaveEnemies(std::list<Enemy> e, std::string fileName){
	fstream f;

	f.open(fileName, ios::out | ios::binary | std::ios::trunc);
	f.write(reinterpret_cast<char*>(&e), e.size() * sizeof(e));
	f.close();

	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;
		f.close();
	}
}

void RecoverEnemies(std::list<Enemy>& e, std::string fileName) {
	fstream f;

	f.open(fileName, ios::in | ios::binary | std::ios::trunc);
	f.read(reinterpret_cast<char*>(&e), e.size()*sizeof(e));
	f.close();


	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;

		f.close();
	}


	for (Enemy& en : e) {
		std::cout << en.id << "-" << en.x << "-" << en.y << endl;
		
		for (Weapen& wa : en.weapon) {
			std::cout << wa.name <<"-" <<wa.power<< endl;
		}
	}
}


void SaveMap(std::map<std::string, int> m, std::string fileName) {
	fstream f;
	f.open(fileName, ios::out | ios::binary | std::ios::trunc);
	f.write(reinterpret_cast<char*>(&m), sizeof(m));
	f.close();

	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;
		f.close();
	}
}

void RecoverMap(std::map<std::string, int>& m, std::string fileName) {
	fstream f;

	f.open(fileName, ios::in | ios::binary | std::ios::trunc);
	f.read(reinterpret_cast<char*>(&m), sizeof(m));
	f.close();


	if (!f.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;

		f.close();
	}


	for (auto pair: m) {
		std::cout << pair.first << "-"<< pair.second<<endl;
	}



}