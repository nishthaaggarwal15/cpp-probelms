#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node *left , *right;
node(int x): val(x), left(NULL), right(NULL){}
};
bool isBBST = true;
int check(node *curr){
    if(curr==NULL)return 0;
    int leftht = check(curr->left);
    int righht = check(curr->right);
    if(abs(leftht-righht)>1) isBBST = false;
    return  max(leftht, righht)+1;
}
int main(){
    return 0;
}