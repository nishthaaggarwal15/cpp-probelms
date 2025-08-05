#include<bits/stdc++.h>
using namespace std;
vector<int> visited;
vector<vector<int>> g;
void bfs(int sourcenode){
queue<int> q; //make a queue
visited[sourcenode]=1; //make current node visited
q.push(sourcenode);//push it to the queue
while(!q.empty()){
    int node = q.front(); //select node and pop it
    q.pop();
    for(auto v: g[node]){ //mark its neighbour visited
        if(!visited[v]){// and push them into the queue
            visited[v]=1;
            q.push(v);
        }
    }
}
}
void solve(){
    int n,m;
    cin>>n>>m;
g.resize(n+1);
visited.resize(n+1,0);
for(int i =0; i<m; i++){
    int a,b;
    cin>> a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
for(int i =1; i<=n; i++){
    if(!visited[i]){
        bfs(i);
    }
}
}
int main(){
solve();
}