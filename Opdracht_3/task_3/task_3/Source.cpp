#include<fstream>
#include <sstream>
#include <iostream>
using namespace std;

// to create random numbers 
#include <cstdalign>
#include<time.h>
int main() {

	int a[10];


	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	std::ofstream myFile;
	myFile.open("save.dat", std::ios::out | std::ios::binary);

	myFile.write(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	myFile.close();

	std::cout << sizeof(char);
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;

		std::cout << a[i] << " - ";
	}

	std::ifstream myFileIN;
	myFileIN.open("save.dat", std::ios::in | std::ios::binary);

	//cheak file corect
	if (!myFileIN.is_open()) {
		std::cout << "could not open file in " << std::endl;
		return 1; 
	}

	//read the file 
	myFileIN.read(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	myFileIN.close();

	return 0;
}