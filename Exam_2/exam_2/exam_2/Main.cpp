#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <list>
#include <cstdalign>
#include<time.h>
using namespace std;

	struct GameObject{
		char type;
		int x; 
		int y;
	};

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


	void SaveObjects(std::vector<GameObject> o, std::string fileName);
	void RecoverObjects(std::vector<GameObject>& o, std::string fileName);

	int main() {
		std::vector<GameObject> objecs;
		std::list<Enemy> enemies;

		//time of the computer
		srand(time(NULL));

		//putting a new character at the back 
		objecs.push_back({ 'c',1,2 });
		objecs.push_back({ 'a',1,2 });
		objecs.push_back({ 'b',1,5 });
		
		//opening file
		string SfileName = "save.dat";

		//getting list size 
		//int sizeobjecs = objecs.size();


		SaveObjects(objecs, SfileName);
		RecoverObjects(objecs, SfileName);



		return 0;
	}

void SaveObjects(std::vector<GameObject> o, std::string fileName) {
	//openfile
	std::ofstream myFile;
	myFile.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
	// writing the size of the object
	std::size_t strSize = o.size();
	myFile.write(reinterpret_cast<char*>(&o), sizeof(size_t));
	myFile.close();


	//check file corect
	if (!myFile.is_open()) {
		std::cout << "file is closed  " << std::endl;
	}
	else {
		std::cout << "file is open " << std::endl;;
	}
}

void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {
	//openfile
	std::ifstream myFileIN;
	myFileIN.open(fileName, std::ios::in | std::ios::binary);
	// reading the file 
	myFileIN.read(reinterpret_cast<char*>(&o), sizeof(int) * 10);
	myFileIN.close();
	//check file corect
	if (!myFileIN.is_open()) {
		std::cout << "fileIn is closed  " << std::endl;
	}
	else{
		std::cout << "fileIn is open " << std::endl;;
	}



}