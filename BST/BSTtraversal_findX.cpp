#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node *left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
node* findval(node *curr, int x){
    if(curr== nullptr) return nullptr;
    if(curr->val==x) return curr;
    else if(x>curr->val){
        return findval(curr->right, x);
    } else{
        return findval(curr->left, x);
    }
}
node * insert(node *curr, int val){
    if(!curr) return new node(val);
    if(val>curr->val) curr->right = insert(curr->right, val);
   else if(val<curr->val) curr->left = insert(curr->left, val);
return curr;
}

int main(){
    int n;
    cin>>n;
    node * root = nullptr;
    for(int i =0; i<n; i++){
        int x;
        cin>>x;
        root = insert(root,x);
    }
    int searchval;
    cin>>searchval;
    node * ans = findval(root, searchval);
    cout<<ans->val<<endl;
    return 0;
}