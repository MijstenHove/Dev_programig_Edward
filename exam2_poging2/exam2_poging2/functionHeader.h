#pragma once
#include<fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <map>

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

void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {
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

	for (GameObject gm : o) {
		std::cout << gm.type << endl;
		std::cout << gm.x << endl;
		std::cout << gm.y << endl;
	}
}


void SaveEnemies(std::list<Enemy> e, std::string fileName) {
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
	f.read(reinterpret_cast<char*>(&e), e.size() * sizeof(e));
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
			std::cout << wa.name << "-" << wa.power << endl;
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


	for (auto pair : m) {
		std::cout << pair.first << "-" << pair.second << endl;
	}
}