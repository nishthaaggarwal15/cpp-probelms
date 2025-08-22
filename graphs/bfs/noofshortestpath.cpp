//SSSP
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 1e9
int n,m;
vector<vector<char>>arr;
using state= pair<int,int>;
vector<vector<int>>dis;
vector<vector<state>>par;
vector<vector<int>>num_path;
bool isvalid(int x, int y){
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#') return true;
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
    int nx = node.F+dx[i];
    int ny = node.S+dy[i];
    if(isvalid(nx,ny)){
        neighs.push_back({nx,ny});
    }
}
return neighs;
}
void bfs(state sourcenode){
dis.assign(n,vector<int>(m,INT_MAX));
par.assign(n,vector<state>(m,{-1,-1}));
num_path.assign(n,vector<int>(m,0));
queue<state> q;

dis[sourcenode.F][sourcenode.S]=0;
par[sourcenode.F][sourcenode.S]={-1,-1};
num_path[sourcenode.F][sourcenode.S]=1;
q.push(sourcenode);
while(!q.empty()){
    state node = q.front();
    q.pop();
    for(state v: neighbours(node)){
        if(dis[v.F][v.S]==INF){
            dis[v.F][v.S]= dis[node.F][node.S]+1;
            num_path[v.F][v.S]= num_path[sourcenode.F][sourcenode.S];
            par[v.F][v.S]=node;
            q.push(v);
        } else if(  dis[v.F][v.S]= dis[node.F][node.S]+1){
     num_path[v.F][v.S]+= num_path[sourcenode.F][sourcenode.S];
        }
    }
}
}
void printpath(state en){
     vector<state>path;
        state curr= en;
        while(curr!=make_pair(-1,-1)){
            path.push_back(curr);
            curr = par[curr.F][curr.S];//will keep going to parent node until reaches first node

        }
        reverse(path.begin(),path.end());
        for(auto v: path){
        cout<<v.F<<" "<<v.S;
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
            cout<<dis[i][j]<<" " << num_path[i][j]<<"\n";
        }
        cout<<endl;
    }
   
}
int main(){
    solve();
    return 0;
}