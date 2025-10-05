#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL),right(NULL){}
};
node *lca(node * root, node* q, node *p){
    while(root){
        if(min(q->val, p->val)> root->val){
            root = root->right;
        } else if(max(q->val, p->val)<root->val){
            root = root->left;
        } else{
            return root;
        }
    }
    return nullptr;
}
int main(){
    return 0;
}