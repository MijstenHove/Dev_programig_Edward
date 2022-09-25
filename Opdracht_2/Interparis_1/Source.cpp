#include <sstream>
#include <iostream>
#include <ios>
#include <ostream>
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"
#include <list>
#include "Header.h"

using namespace std;

int printfunc(string a, string b, string c) {

	printEnemy printenemy;
	 
	for (int i = 0; i < printenemy.wapons.size(); i++) {
		
	
			cout << printenemy.wapons[i] << endl;
		
	}
	return 0;
}


int main() {


	//list <string>enemylist ();

	//get rapidxml ready
	rapidxml::xml_document<> doc;
	//open file
	std::ifstream file("res/files/xml/config.xml");
	//create buffer
	std::stringstream buffer;
	//copy the open file 
	buffer << file.rdbuf();
	//close the file 
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	//print the info 
	std::cout << "name of the raiz:" << doc.first_node()->name() << "\n";
	std::cout << std::endl;
	// get pointer to the first node 
	rapidxml::xml_node<>* pRoot = doc.first_node();
	vector <printEnemy> printenemy;
	
	//iterare each "enemy"
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("enemy"); pNode; pNode = pNode->next_sibling()) {
		
		printEnemy newEnemy;
		string newHP = pNode-> first_node("hp")->value();
		string newEP = pNode->first_node("Experience")->value();
		string newAttack = pNode->first_node("Attack")->value();

		std::cout << newHP << std::endl;
		//newEnemy = newEnemy(nHP, newEP, newAttack);
	
		//wepon
		string newEnemyName = pNode->first_node("wapon")->value();
		for (rapidxml::xml_node<>* pChild = pNode->first_node("wapons"); pChild; pChild = pChild->next_sibling()) {
			
			printWapon newwapon;
			string newID = pNode->first_node("IDwapon")->value();
			string newType = pNode->first_node("type")->value();
			string newRange = pNode->first_node("range")->value();
			//newwapon = printWapon(newID, newType, newRange);
		}
		printenemy.push_back(newEnemy);

		std::cout << std::endl;
	}
	
	// object

	return 0;
}
