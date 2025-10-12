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
   if(curr->left!=NULL){// if left side is there
    node * temp = curr->left;// store the curr to temp 
    while(temp->right !=NULL && temp->right!=curr ){// keep moving to right until you find the last node that is either null or connected
        temp = temp->right;
    }
    if(temp->right == curr){// if active
temp->right = NULL;// make it not active
cout <<curr->val<<endl;// left side is done now print it
curr = curr->right;// move to the right
    } else{
        temp->right= curr;// if not active , activate it
        curr = curr->left;// move to next node on left
    }
   } else{
    cout<<curr->val; //now left part is done print the curr node
    curr = curr->right;// move to the right
   }
    }
}
int main(){
    return 0;
}