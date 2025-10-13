// C++ code to check if two trees are 
// isomorphic using recursion
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to check if two trees are isomorphic
bool isIsomorphic(Node* root1, Node* root2) {
  
    // Both roots are NULL, trees are isomorphic
    // by definition
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    // Exactly one of the root1 and root2 is NULL, 
    // trees not isomorphic
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    // If the data doesn't match, trees 
    // are not isomorphic
    if (root1->data != root2->data) {
        return false;
    }

    // Check if the trees are isomorphic by 
    // considering the two cases:
    // Case 1: The subtrees have not been flipped
    // Case 2: The subtrees have been flipped
    return (isIsomorphic(root1->left, root2->left) &&
            isIsomorphic(root1->right, root2->right)) ||
           (isIsomorphic(root1->left, root2->right) &&
            isIsomorphic(root1->right, root2->left));
}

int main() {
  
    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       / \
    //      7   8
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      3   2
    //     /   / \
    //    6   4   5
    //           / \
    //          8   7
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->left = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    if (isIsomorphic(root1, root2)) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }

    return 0;
}