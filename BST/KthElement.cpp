#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
int KthSmallest(node *root,int k){
if(!root)return -1;
int left = KthSmallest(root->left,k);
if(left!=-1) return left;
k--;
if(k==0)return root->val;
return KthSmallest(root->right,k);
}
int findKth(node*root, int k){
    return KthSmallest(root,k);
}
int main(){
    return 0;
}