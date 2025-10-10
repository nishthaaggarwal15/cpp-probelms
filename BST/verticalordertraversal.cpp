#include<bits/stdc++.h>
using namespace std;
using state = pair<int,int>;
struct node{
int val;
node * left, *right;
node(int x): val(x), left(NULL),right(NULL){}
};
vector<vector<int>> VerticalOrder(node *root){
queue<pair<node *, state>> q;
map<int, map<int,multiset<int>>> mp;
q.push({root,{0,0}});
while(!q.empty()){
     auto p = q.front();
q.pop();
node * curr = p.first;
int vertical= p.second.first;
int level = p.second.second;
mp[vertical][level].insert(curr->val);
if(curr->left){
    q.push({curr->left,{vertical-1,level+1}});
}
if(curr->right){
    q.push({curr->right,{vertical+1,level+1}});
}

}
vector<vector<int>>ans;
for(auto& p: mp){
    vector<int>col;
    for(auto& q: p.second){
col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
}
return ans;
}
int main(){
    return 0;
}