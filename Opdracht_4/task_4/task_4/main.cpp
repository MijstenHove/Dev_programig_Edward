#include <sstream>
#include <fstream>
#include <ios>
#include <iostream>
#include <exception>
#include <string>

#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

int main() {
	/*
	try
	{
		// open file
		std::ifstream file;
		file.open("res/files/xml/bookstore.xml");


		if (!file.is_open()) {
			throw std::exception( "i cant open the file");
		}

		//read the xml file
		rapidxml::xml_document<> doc;
		stringstream buff;
		buff << file.rdbuf();

		//parse the xml file
		string str = buff.str();
		doc.parse<0>(&str[0]);

		file.close();

		///std::cout <<"someting in spanich " <<doc.first_node()->name<<
	}
	//
	catch (catch (std::exception c) {
		std::cout << "error: " << c.what();
	}
	
	catch (char* c) {
		std::cout << "error: " << c.what();
	} c) {
		std::cout <<"error: "<< c.what();
	}
	/*/


	//try chatsh
	bool validname = false;
	std::string name;

	do {
		std::cout << "enter name: ";
		std::cin >> name;
		try {
			if (strcmp(name.c_str(), "mijs"))
				throw std::exception("not correct!! try aggen \n");
			validname = true;
		}
		catch (std::exception c) {
			std::cout << c.what() << std::endl;
		}
	} while (!validname);


	return 0;
}



