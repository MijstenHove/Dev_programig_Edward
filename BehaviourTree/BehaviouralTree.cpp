#include "BehaviouralTree.h"

//public
BehaviouralTree::BehaviouralTree(Node* rootnode) {
	root = rootnode;
}
BehaviouralTree::~BehaviouralTree() {
	// destroy entity 
	Exit(root);
}

Node* BehaviouralTree::Search(int value) {
	return Search(root, value);
}
bool BehaviouralTree::Exists(int value) {
	return Search(value) != nullptr;
}

void BehaviouralTree::PreOrder() {
	PreOrder(root);
}
void BehaviouralTree::InOrder() {
	InOrder(root);
}

void BehaviouralTree::PostOrder(Node* node) {
	
	if (node == NULL)
		return;
	PostOrder(node->left);

	// then recur on right subtree
	PostOrder(node->right);

	// now deal with the node
	std::cout << node->value<< ">";
}

// private
	Node* BehaviouralTree::Search(Node * node, int value) {
		Node* returnvaluw = nullptr;
		if (root->left != nullptr)
			returnvaluw = Search(root->left, value);

		if (root->value == value && returnvaluw == nullptr)
			returnvaluw = root;

		if (root->right != nullptr)
			returnvaluw = Search(root->right, value);

		return returnvaluw;

	}

	void BehaviouralTree::PreOrder(Node * node) {

		if (node == NULL)
			return;

		std::cout << node->value << ">";

		InOrder(node->left);
		InOrder(node->right);
		/*if (node->left != nullptr) {
			std::cout << node->value << ">";
			InOrder(node->left);
		}

		if (node->right != nullptr) {
			//std::cout << node->value << ">";
			InOrder(node->right);
		}*/
	}
	void BehaviouralTree::InOrder(Node * node) {
		if (node->left != nullptr)
			InOrder(node->left);

		std::cout << node->value << ">";

		if (node->right != nullptr)
			InOrder(node->right);


	}
	void BehaviouralTree::Exit(Node* node) 
	{
		/*while (node != NULL) {

			if (node->left != nullptr)
				Exit(node->left);

			if (node->right != nullptr)
				Exit(node->right);

			std::cout << "\n Deleting node: ";
			delete node;
		}*/
	}