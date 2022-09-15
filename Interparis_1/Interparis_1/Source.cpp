#include <sstream>
#include <iostream>
#include <ios>
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

int main(){
	//get rapidxml ready
	rapidxml::xml_document<> doc;
	//open file
	std::ifstream file("res/files/xml/bookstore.xml");
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
	std::cout << "text of the raiz:" << doc.first_node()->name() << "\n";

	// get pointer to the first node 
	rapidxml::xml_node<>* pRoot = doc.first_node();

	//iterare each "book"
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("book"); pNode; pNode = pNode->next_sibling()) {
		std::cout << pNode->name() << ":" << std::endl;

		for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {
			std::cout << pChild-> name() << ":" << std::endl;
		}
		std::cout << std::endl;
	}


	return 0;
}