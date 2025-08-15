#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>indeg;
vector<int> topo;
int n,m;
void kahns(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(auto v: g[cur]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
}
int main(){

    cin>>n>>m;
    g.resize(n+1);
  indeg.assign(n+1,0);
    topo.assign(n,0);
    for(int i =0; i<n; i++){
        int a,b;
        cin>>a>>b;
     g[a].push_back(b);
     indeg[b]++;
     //outdeg[a]++;
    }
kahns();
//to check if there is a cycle or not 
// if(topo.size()!=n) cout<<"there is a cycle"<<'\n';
// else cout<<"there is a cycle"<<'\n';

// toprint topo
for(auto v: topo){
    cout<<v<<endl;
}
    return 0;
}