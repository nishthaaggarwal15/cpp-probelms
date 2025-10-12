#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left,*right;
node(int x) : val(x),left(NULL),right(NULL){}
};
int coundNodes(node *curr){
    int count =0;
while(curr!=NULL){
    if(curr->left!=NULL){
node * temp = curr->left;
while(temp->right!=NULL && temp->right!=curr){
temp = temp->right;
}
if(temp->right ==curr){
    temp->right = NULL;
    count++;
    curr = curr->right;

} else{
    temp->right = curr;
    curr = curr->right;
}
    } else{
        count++;
        curr= curr->right;
    }
}
return count;
}
int findmedian(node *curr){
    if(!curr) return 0;
    int total = coundNodes(curr);
    int currcount =0;
    float m1 =-1, m2=-1;
    while(curr!=NULL){
        if(curr->left!=NULL){
            node * temp = curr->left;
            while(temp->right!=NULL && temp->right!=curr){
                temp = temp->right;
            }
            if(temp->right==curr){
                temp->right = NULL;
                currcount++;
                if(total % 2!=0 &&currcount == (total+1)/2){
return curr->val;
                } else if(total%2==0 && currcount== total/2|| currcount== total/2+1 ){
                    if(m1==-1) m1= curr->val;
                    else return(m1+curr->val)/2.0;
                }
                curr= curr->right;
            } else{
                temp->right = curr;
                curr = curr->left;
            }
        } else{
            currcount++;
            if (total % 2 != 0 && currcount == (total + 1) / 2)
                return curr->val;
            else if (total % 2 == 0 && (currcount == total / 2 || currcount == total / 2 + 1)) {
                if (m1 == -1) m1 = curr->val;
                else return (m1 + curr->val) / 2.0;
            }
            curr =curr->right;
        }
    }
}
int main(){
    return 0;
}