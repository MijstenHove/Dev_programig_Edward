#include "BehaviouralTree.h"

int main() {

    /*create root*/
    Node* root = new Node(1);

    //level 2
    root->left = new Node(2);
    root->right = new Node(3);

    //level 3 
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //level 3 
    root->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
   
    BehaviouralTree theTree(root);
    theTree.InOrder(); // from unther to root
    std::cout << std::endl;
    theTree.PreOrder(); // top to botum left to right 
    std::cout << std::endl;
    theTree.PostOrder(root);
    theTree.~BehaviouralTree();

    return 0; 
	
}