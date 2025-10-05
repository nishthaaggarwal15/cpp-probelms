#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
node * lca(node * root,node *p, node *q){
    if(root==nullptr|| p==root||q==root){
        return root;
    }
    node * left = lca(root->left, p,q);
    node * right = lca(root->right, p,q);
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    return (left!=nullptr)? left :right;
}
int main(){
    return 0;
}