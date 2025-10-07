#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node *left,*right;
node(int x): val(x), left(NULL), right(NULL){}
};
int ans =0;
int k;
void dfs(node *root, int currsum, unordered_map<int,int> &mp){
if(!root) return ;
currsum+= root->val;
ans+= mp[currsum-k];
mp[currsum]++;
dfs(root->left,currsum,mp);
dfs(root->right,currsum,mp);
mp[currsum]--;
}
int count(node *root, int target){
ans =0;
k= target;
unordered_map<int,int> mp;
mp[0]=1;
dfs(root,0,mp);
return ans;
}
int main(){
    return 0;
}