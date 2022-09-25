#include<fstream>
#include <sstream>
#include <iostream>
#include <vector>



using namespace std;

// to create random numbers 
#include <cstdalign>
#include<time.h>
int main() {
	std::vector<int> grades;

	for (int i = 0; i < 10; i++) {
		grades.push_back(i);
	}
	
	int size = grades.size();
	
	srand(time(NULL));

	std::string s = "hola k ase";
	int a[10];

	std::ofstream myFile;
	myFile.open("save.dat", std::ios::out | std::ios::binary | std::ios::trunc);
	// writing the size of the string 
	std::size_t strSize = s.size();


	myFile.write(reinterpret_cast<char*>(&a), sizeof(size_t));
	myFile.close();
	
	std::ifstream myFileIN;
	myFileIN.open("save.dat", std::ios::in | std::ios::binary);

	//read the file 
	myFileIN.read(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	myFileIN.close();


	std::cout << sizeof(char);
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;

		std::cout << a[i] << " - ";
	}

	//cheak file corect
	if (!myFileIN.is_open()) {
		std::cout << "could open file in " << std::endl;
		return 1; 
	}
	else
	{
		std::cout << "could not open file in " << std::endl;
		return 1;
	}

	//read the size of the string
	size_t inSize;
	myFileIN.read(reinterpret_cast<char*>(&inSize), sizeof(size_t));
	char* ptr = new char[inSize + 1];
	myFileIN.read(ptr, inSize);
	ptr[inSize] = '\0';
	std::string instring = ptr;

	delete[] ptr;
	myFileIN.close();

	//meet.goolge.com/sif-zwzt-mqm this was on the bord 
	return 0;
}