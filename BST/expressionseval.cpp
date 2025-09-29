#include<bits/stdc++.h>
using namespace std ;
struct node{
   string val;
    node * left;
    node * right;
    node(string x ):val(x), left(NULL), right(NULL){}
};
bool isoperator(const string &s){
    if(s=="-"|| s=="+"|| s=="/"|| s=="*") return true;
}
int handlecase(const string &op, int left, int right){
    if(op=="+")return left+right;
        if(op=="-")return left-right;
            if(op=="/")return left/right;
                if(op=="*")return left*right;
                return 0;
}
int evaltree(node * curr){
if(isoperator(curr->val)){
    int leftval = evaltree(curr->left);
    int rightval = evaltree(curr->right);
    return handlecase(curr->val,leftval,rightval);
}
return stoi(curr->val);
}
int main(){
    return 0;
}