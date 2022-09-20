#include <sstream>
#include <iostream>
#include <ios>
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"


using namespace std;

void printfunc(rapidxml::xml_node<>* pRood) {
	

	


	std::cout << pRood->name() << ": " << pRood->value() << std::endl;
}



int main() {
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

	// list the enemies


	//iterare each "enemy"
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("enemy"); pNode; pNode = pNode->next_sibling()) {
		printfunc(pNode);

		for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {
			printfunc(pChild);
			std::cout << std::endl;
			
			//wapons
			for (rapidxml::xml_node<>* pAdd = pChild->first_node(); pAdd; pAdd = pAdd->next_sibling()) {

				if (pAdd->next_sibling() != NULL){
					printfunc(pAdd);
				}
			}
		}
	}

	
	std::cout << std::endl;
	return 0;
}
