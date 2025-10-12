#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};



int getInorderSuccessor(Node *node, int k)
{
    // Complete the 
    Node * successor = NULL;
    while(node!=NULL){ // when we reach null means the currently stored one is succesor
        if(k>=node->val){ // if curr val is smaller than k then we have to find it on right side
            node = node->right;
        }else{
            successor = node; // if curr val is greater itmay be succesor so we store it just in case and search left for smaller one
            node = node->left;
        }
    }
  return successor ? successor->val : -1;    return successor->val;
}
int main(){
    return 0;
}