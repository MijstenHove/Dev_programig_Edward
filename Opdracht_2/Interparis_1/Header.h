#include <sstream>
#include <iostream>
#include <ios>
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

using namespace std;
class printEnemy {
public:
	//info enemy
	std::string name; 
	int hp;
	int Experience;
	int Attack;

	//wapon
	std::string IDwapon;
	std::string type;
	int range;

};