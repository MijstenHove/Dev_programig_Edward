#pragma once
class Node
{
public: 
	int value;
	Node* left;
	Node* right;
	Node() : value(0), left(nullptr), right(nullptr) {};
	Node(int value) : value(value), left(nullptr), right() {};
};

