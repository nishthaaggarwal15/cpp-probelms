#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
     node *left, *right;
     node(int x): val(x), left(NULL), right(NULL){}
};
vector<int> DiagonalOrder (node *root){
vector<int> ans;
if(!root) return ans;
queue<node*> q;
q.push(root);
while(!q.empty()){
    node * curr = q.front();
    q.pop();
    while(curr){
     ans.push_back(curr->val);
     if(curr->left)
     q.push(curr->left);
     curr = curr-> right;
    }
}
    
}
int main(){
    return 0;
}