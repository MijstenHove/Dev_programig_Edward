
#include <sstream>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <exception>

#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

int main2() {

	bool validname = false;
	std::string name;

	do {
		std::cout << "enter name: ";
		std::cin >> name;
		try{
			if (strcmp(name.c_str(), "mijs"))
				throw std::exception("not correct!! try aggen \n");
				validname = true;
		}
		catch (std::exception c){
			std::cout << c.what() << std::endl;
		}
	} while (!validname);

	
	return 0;
}