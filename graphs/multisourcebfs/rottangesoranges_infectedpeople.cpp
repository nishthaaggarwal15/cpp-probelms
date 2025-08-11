#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n,m;
vector<vector<int>>grid;
vector<vector<int>> dist;
using state =  pair<int,int>;
queue<state> q;
int healthy;
int maxtime;
int dx[]= {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool isvalid(int x, int y ){
if(x>=0 && y>=0 && x<n&& y<m && dist[x][y]==-1 && grid[x][y]==1) return true;
return false;
}
int bfs(){
    maxtime =0;
while(!q.empty()){
    state s = q.front();
    q.pop();
    int x = s.F;
    int y = s.S;
    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(isvalid(nx,ny)){
            dist[nx][ny]= dist[x][y]+1;
            maxtime = max(maxtime, dist[nx][ny]);
            healthy--;
            q.push({nx,ny});

        }
    }

}
return (healthy>0) ? -1: maxtime;
}
void solve(){
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));
    dist.resize(n,vector<int>(m,-1));
    healthy =0;
    for(int i =0; i<n; i++){
        for(int j =0; j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]==2){
             q.push({i,j});
             dist[i][j]=0; //dist from current 2
            } else if(grid[i][j]==1){
healthy++;
            }
        }
    }
    cout<<bfs()<<'\n';
}
int main(){
    solve();
    return 0;
}