// C++ Program to Remove all leaf nodes
// from the binary search tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
      	right = nullptr;
    }
};


// Function for inorder traversal in a BST.
void inorder(Node* root) {
  
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Delete leaf nodes from binary 
// search tree.
Node* leafDelete(Node* root) {
  
    if (root == nullptr)
        return nullptr;
    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
    }

    // Recursively delete in left and 
  	// right subtrees.
    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);

    return root;
}

int main() {
  
    // Create a hard coded BST.
    //        20
    //       /  \
    //      8   22
    //     / \
    //   4   12
    //       /  \
    //     10   14
  
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
  
    leafDelete(root);
    inorder(root);
    return 0;
}