#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 
using state = pair<int, int>;
stack<state> history; // node, oldsize
const int N = 100005;
int parent[N], sz[N];
void init(int n){
for(int i =0; i<n; i++){
    parent[i]= i;
    sz[i]=1;
}
}

int find(int x ){
while(parent[x]!=x){
    x = parent[x];
}
return x;
}

bool unite(int a , int b){
a = find(a);
b = find(b);
if(a==b){
    history.push({-1,-1});
    return false;
}
if(sz[a]<sz[b]) swap(a,b);
history.push({b,sz[a]});
parent[b]=a;
sz[a]+= sz[b];
return true;
}
void rollback(){
state s= history.top();
history.pop();
int b = s.F;
int oldsize = s.S;
if(b==-1) return;
int a = parent[b]; 
sz[a]= oldsize;
parent[b]=b;
}
void solve(){
int n ;
cin>>n;
init(n);
unite(1,2);
unite(2,3);

cout<< (find(1)== find(3))<<endl;
rollback();
cout<< (find(1)== find(3))<<endl;
}
int main(){
    solve();
    return 0;
}