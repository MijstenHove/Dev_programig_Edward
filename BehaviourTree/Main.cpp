#include "BehaviouralTree.h"]

int main() {
	BehaviouralTree tree;

    /*create root*/
    Node* root = new Node(1);

    /* following is the tree after above statement
    1
    / \
    NULL NULL
    */
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    tree.InOrder();

    return 0; 
	
}