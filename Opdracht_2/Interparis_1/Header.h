#include <sstream>
#include <iostream>
#include <ios>
#include <vector>;
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
	vector<printWapon> wapons;

};

class printEnemy {
public:
	//info enemy
	string hp;
	string experience;
	string attack;
	
	
	//cout << "Test" << std::endl;
	vector<printEnemy> wapons;

};