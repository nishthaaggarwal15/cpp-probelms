#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
#define INF 100009
#define F first
#define S second
bool isBST = true;
pair<int,int> check(node *curr){
    if(curr==NULL){
        return {INF,-INF};
    }
    pair<int,int> leftval = check(curr->left);
    pair<int,int> rightval= check(curr->right);
    if(leftval.S>=curr->val) isBST= false;// max of left
    if(rightval.F<= curr->val)isBST = false;//min of right
    return {min(leftval.F,curr->val), max(rightval.S,curr->val)};
}
int main(){
    return 0;
}