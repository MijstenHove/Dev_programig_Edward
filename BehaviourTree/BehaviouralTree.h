#pragma once
#include "Node.h"
#include <iostream>
class BehaviouralTree
{
	// binarytree
public:
	BehaviouralTree(Node* rootnode);
	~BehaviouralTree();
	Node* Search(int value);
	void PreOrder();
	void InOrder();
	void PostOrder(Node* node);
	bool Exists(int value);

private:
	Node* root;
	Node* Search(Node* node, int value);
	void PreOrder(Node* node);
	void InOrder(Node* node);
	void Exit(Node* node);

};

