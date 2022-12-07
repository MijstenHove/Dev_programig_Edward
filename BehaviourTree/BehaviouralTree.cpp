#include "BehaviouralTree.h"

Node* BehaviouralTree::Search(Node* node, int value) {
Node* returnvaluw = nullptr;
	if (root->left != nullptr) 
		returnvaluw = Search(root->left, value);
	
	if (root->value == value && returnvaluw == nullptr)
		returnvaluw = root;

	if (root->right != nullptr)
		returnvaluw = Search(root->right, value);

	return returnvaluw;

}

Node* BehaviouralTree::Search(int value) {
	return Search(root, value); 
}

bool BehaviouralTree::Exists(int value) {
	return Search(value) != nullptr;
}
void  BehaviouralTree::PreOrder(Node* node) {

}

void BehaviouralTree::InOrder(Node* node) {
	if (node->left != nullptr)
		InOrder(node->left);
	
	std::cout << node->value << ">";

	if (node->right != nullptr)
		InOrder(node->right);
}
void BehaviouralTree::PreOrder() {


}
void BehaviouralTree::InOrder() {


}

void BehaviouralTree::PostOrder() {

}