#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	std::ifstream dataFile("MijsFile.txt");
	if (!dataFile.is_open()) {
		std::cout << "There was an error opening the data file" << std::endl;
		return 1;
	}
	// class data reading
    std:string className = "";
	float classNumber = 0.0;
	dataFile >> className >> classNumber;


	//Info that is needed
	int students = 0;
	float averageHeight = 0;
	std::string thirdStudent = "";

	while (!dataFile.eof()) {
		//Add a student
		students++;
		//Store memory to read the data
		std::string name;
		float age;
		float height;
		//Read the data
		dataFile >> name >> age >> height;
		averageHeight += height;
		//Special case
		if (students == 3)
			thirdStudent = name;
	}

	//Close the file since we're not going to use it anymore
	dataFile.close();

	//Calculate the average height
	averageHeight /= (float)students;

	//Print the final result
	std::cout << "Amount of students: " << students << std::endl;
	std::cout << "Third student: " << thirdStudent << std::endl;
	std::cout << "Average height: " << averageHeight;

	std::cout << std::endl << "Los delegados de la clase " << className << " numero " << classNumber << " son dos" << std::endl;

	return 0;
}

	
	/*int age[]{ 11,12,12,13};
	std::string name[]{ "aya", "ben", "cloe", "derk" };
	float hight[]{ 5.2f,5.1f,5.1f,5.3f };



	for (int i = 0; i < 4; i++) {
		outFile <<  age[i]<< "  " << name[i] << "  "<< hight[i] << endl;	

		
	}

	int newsize = sizeof(name) / sizeof(*name);
	cout << "kid amound "<< newsize << endl;
	// thirsd student 
	// average hight
	//
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


