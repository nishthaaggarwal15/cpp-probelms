#include<bits/stdc++.h>
using namespace std;
struct node {
int val;
node *left,*right;
node(int x): val(x), left(NULL), right(NULL){}
};
int dfs(node *curr,int &ans){
    if(curr==NULL) return 0;
    int lc = dfs(curr->left,ans);
    int rc = dfs(curr->right,ans);
    ans = max(ans,lc+1+rc);
    return max(lc,rc)+1;
}
int main(){
    return 0;
}