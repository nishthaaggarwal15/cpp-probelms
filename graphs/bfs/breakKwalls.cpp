//SSSP
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 1e9
int n,m,k;
vector<vector<char>>arr;
using state= pair<pair<int,int>,int>;
vector<vector<vector<int>>>dis;
bool isvalid(int x, int y){
if(x>=0 && x<n && y>=0 && y<m) return true;
return false;
}
//for knights 
//int dx[]= {2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};
int dx []= {0,1,0,-1};
int dy[]= { 1,0,-1,0};
vector<state> neighbours(state node){
vector<state> neighs;
for(int i =0; i<4; i++){
    int nx = node.F.F+dx[i];
    int ny = node.F.S+dy[i];
    if(isvalid(nx,ny)){
        int nz = node.S;
        if(arr[nx][ny]=='#') nz+=1;
        if(nz>k)continue;
        neighs.push_back({{nx,ny},nz});
    }
}
return neighs;
}
void bfs(state sourcenode){
dis.assign(n,vector<vector<int>>(m,vector<int>(k+1,INF)));

queue<state> q;

dis[sourcenode.F.F][sourcenode.F.S][sourcenode.S]=0;
q.push(sourcenode);
while(!q.empty()){
    state node = q.front();
    q.pop();
    for(state v: neighbours(node)){
        if(dis[v.F.F][v.F.S][v.S]==INF){
            dis[v.F.F][v.F.S][v.S]= dis[node.F.F][node.F.S][node.S]+1;
    
            q.push(v);
        }
    }
}
}
void solve(){
    cin>>n>>m>>k;
    arr.resize(n);
   pair<int,int>  st,en;
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
    bfs({st,0});
    // min ans after breaking any number of walls upto k
    // as we want min ans after breaking any no. of balls upto k 
    // and task to optimize the ans (dist) not number of walls
int ans =0;
for(int walls =0; walls<=k; walls++){
    ans = min( dis[en.F][en.S][walls],ans);
}
   cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}