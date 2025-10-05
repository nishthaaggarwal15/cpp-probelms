#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
node* lca(node *root, node* q, node* p){
    if(root==nullptr|| p ==nullptr|| q==nullptr){
        return root;
    }
    if(root->val> p->val && root->val > q->val){
        return lca(root->left, q,p);
    }
     if(root->val< p->val && root->val < q->val){
        return lca(root->right, q,p);
    }
    return root;
}
int main(){
    return 0;
}