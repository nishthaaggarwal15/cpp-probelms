#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
void inorder(node * root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}
node * mergetree(node * p1, node * p2){
if(p1==nullptr) return p2;
if(p2==nullptr) return p1;
stack<pair<node* ,node* >>s;
s.push({p1,p2});
while(!s.empty()){
   auto n = s.top();
    s.pop();
    node * n1 = n.first;
    node * n2 = n.second;
    if(n1==nullptr|| n2==nullptr) continue;
    n1->val+= n2->val;
    if(n1->left == nullptr){
        n1->left = n2->left;
    }
else{
    s.push({n1->left, n2->left});
}
if(n1->right==nullptr){
    n1->right= n2->right;
} else{
s.push({n1->right, n2->right});
}
}
return p1;
}
int main(){
    return 0;
}