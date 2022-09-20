#include <sstream>
#include <iostream>
#include <ios>
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

using namespace std;
class printWapon {
public:

	string IDwapon;
	string type;
	string range;


};

class printEnemy {
public:
	//info enemy
	string hp;
	string experience;
	string attack;
	
	
	std::cout <<hp<< std::endl;
	vector<printWapon> wapons;

};