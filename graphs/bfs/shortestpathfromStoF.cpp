//SSSP
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n,m;
vector<vector<char>>arr;
using state= pair<int,int>;
vector<vector<int>>vis;
vector<vector<int>>dis;
bool isvalid(int x, int y){
if(x>0 && x<n && y>0 && y<m && arr[x][y]!='#') return true;
return false;
}
int dx []= {0,1,0,-1};
int dy[]= { 1,0,-1,0};
vector<state> neighbours(state node){
vector<state> neighs;
for(int i =0; i<4; i++){
    int nx = node.F+dx[i];
    int ny = node.S+dy[i];
    if(isvalid(nx,ny)){
        neighs.push_back({nx,ny});
    }
}
return neighs;
}
void bfs(state sourcenode){
vis.assign(n,vector<int>(m,0));
dis.assign(n,vector<int>(m,INT_MAX));
queue<state> q;
vis[sourcenode.F][sourcenode.S]=1;
dis[sourcenode.F][sourcenode.S]=0;
q.push(sourcenode);
while(!q.empty()){
    state node = q.front();
    q.pop();
    for(state v: neighbours(node)){
        if(!vis[v.F][v.S]){
            vis[v.F][v.S]=1;
            dis[v.F][v.S]= dis[node.F][node.S]+1;
            q.push(v);
        }
    }
}
}
void solve(){
    cin>>n>>m;
    arr.resize(n);
     state st,en;
    for(int i =0; i<n; i++){
    arr[i].resize(m);
     for(int j=0; j<m; j++){
        cin>>arr[i][j];
        if(arr[i][j]=='S'){
            st= {i,j};
        } else if(arr[i][j]=='F'){
            en= {i,j};
        }
    }
    }
    bfs(st);
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cout<<dis[i][j]<<"\n";
        }
        cout<<endl;
    }
    if(!vis[en.F][en.S]){
        cout<<"Final state not reachable\n";
    }
    else{
        cout<<dis[en.F][en.S]<<endl;
    }
}
int main(){
    solve();
    return 0;
}