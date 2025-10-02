#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node *left, *right;
node(int x): val(x),left(NULL), right(NULL){}
};
void flip(node * curr){
    if(curr==NULL) return;
    swap(curr->left, curr->right);
    flip(curr->left);
    flip(curr->right);
}
int main(){
    return 0;

}