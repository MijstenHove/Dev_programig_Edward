#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream outFile;

	outFile.open("mijsFile.txt");

	int age[]{ 11,12,12,13};
	string name[]{ "aya", "ben", "cloe", "derk" };
	float hight[]{ 5.2f,5.1f,5.1f,5.3f };

	for (int i = 0; i < 4; i++) {
		outFile <<  age[i]<< "  " << name[i] << "  "<< hight[i] << endl;
		
	}

	outFile.close();

	return 1;
	/*std::ofstream outFile("mijs.tenhove", std::ios::app);

	if (!outFile.is_open()) {
		std::cout << "thare is a error opening the file";

		return 1;
	}

	for (int i = 0; i < 10; i++) {
		outFile << "hola!" ;
	}
		outFile.flush();
		outFile.close();

		return 0;
	
	



	/*file format

		class name { sting } - class number { float }
	number{ sting } - age{ int } - height{ float }
		number{ sting } - age{ int } - height{ float }
		number{ sting } - age{ int } - height{ float }
		....

		number of students
		the cloud of the 3rd student
		Average height

		"class delegate [name] number [class num] is two"*/


}