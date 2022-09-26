#include<fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// to create random numbers 
#include <cstdalign>
#include<time.h>

struct GameObject
{
	char name[50];
	int age;
	float gpa;
};

void SaveObjects(std::vector<GameObject>& o, std::string fileName);
void RecoverObjects(std::vector<GameObject>& o, std::string fileName);
int main() {
	std::vector<GameObject> objecs;
	objecs.push_back ({ "mijs",23, 3.5 });
	
	SaveObjects(objecs, "save.dat");
	RecoverObjects(objecs, "save.dat");

 return 0;
}

void SaveObjects(std::vector<GameObject>& o, std::string fileName) {
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


	for (GameObject gm : o){
		std::cout << gm.name << endl;
		std::cout << gm.age << endl;
		std::cout << gm.gpa << endl;
	}
}