#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node * left , *right;
node(int x): val(x), left(NULL), right(NULL){}
};
void preorder(node *curr){
    while(curr!=NULL){
        if(curr->left!=NULL){
            node * temp = curr->left;
            while(temp->right!=NULL && temp->right!=curr){
                temp= temp->right;
            }
            if(temp->right==curr){
                temp->right = NULL;
                curr = curr->right;
            } else{
                cout<<curr->val<<endl;
                temp->right = curr;
                curr = curr->left;
            }
        }else{
            cout<<curr->val;
            curr = curr->right;
        }
    }
}
void printInorder(node *curr){
    while(curr!=NULL){
   if(curr->left!=NULL){
    node * temp = curr->left;
    while(temp->right !=NULL && temp->right!=curr ){
        temp = temp->right;
    }
    if(temp->right == curr){// active
temp->right = NULL;
cout <<curr->val<<endl;
curr = curr->right;
    } else{
        temp->right= curr;
        curr = curr->left;
    }
   } else{
    cout<<curr->val;
    curr = curr->right;
   }
    }
}
int main(){
    return 0;
}