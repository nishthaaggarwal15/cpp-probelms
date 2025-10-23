#include<bits/stdc++.h>
using namespace std;
struct node{
int val;
node * left, *right;
node(int x): val(x), left(NULL), right(NULL){}
};
node * findTar(node * root,  int target, unordered_map<node* , node*> parents){
    node * left = nullptr, *right = nullptr;
    /*If left subtree found it → it returns the pointer to that node.

Otherwise, if right found it → return that.

If neither found it and current node isn’t target → return nullptr.*/
    if(root->left!=nullptr){
        parents[root->left]= root;
        left = findTar(root->left, target, parents);
    }
    if(root->right !=nullptr){
        parents[root->right]= root;
        right = findTar(root->right,target, parents);
    }
    if(root->val== target){
        return root;
    }
    if(left!=nullptr){
        return left;
        //means target is onleft side
    }
    return right;
}
void dfs(node * root, node*prev, int k,unordered_map<node*, node*>&parents, vector<int>&ans){
if(root==nullptr){
    return;
}
if(k==0){
    ans.push_back(root->val);
    return;
}
//if there isnt a cycyle
if(root->left!=prev){//for left
    dfs(root->left, root,k-1,parents,ans);
}
if(root->right!=prev){//for right
    dfs(root->right, root,k-1,parents,ans);
}
if(parents[root]!=prev){//for upward
dfs(parents[root], root,k-1, parents,ans);
}

}
vector<int> KDistanceNodes(node *root, int target, int k) {
    vector<int> ans;

    if (root == nullptr)
        return ans;
    
    // find the target nodes and map the nodes
    // to their parent nodes.
    unordered_map<node *, node *> parent;
    node *tar = findTar(root, target, parent);

    dfs(tar, nullptr, k, parent, ans);

    // sort the result
    sort(ans.begin(), ans.end());

    return ans;
}
int main(){
    return 0;
}