//The first input line has two integers n and m: the height and width of the map.
//Then there are n lines of m characters describing the 
// map. Each character is either ‘.’ (floor) or '#' (wall).
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> visited;
vector<string> grid;
int dx[]= {0,0,1,-1};
int dy[]= {-1,1,0,0};
bool isvalid(int x, int y){
    if(x>=0&& x<n && y>=0&& y<m && grid[x][y]=='.' && !visited[x][y]) return true;
    return false;
}
void dfs(int x, int y){
visited[x][y]= 1;
for(int i =0; i<4; i++){
    int nx = x+dy[x];
    int ny= y+dy[y];
    if(isvalid(nx, ny)){
        dfs(nx,ny);
    }
}
}
void solve(){
cin>>n>>m;
grid.resize(n);
visited.resize(n);
for(int i =0; i<n; i++){
    cin>>grid[i];
}
int rooms=0;
for(int i =0; i<n; i++){
    for(int j =0; j<m; j++){
        if(grid[i][j]='.'&& !visited[i][j]){
            dfs(i,j);
            rooms++;
        }
    }
}
cout<<rooms<<"\n";
}
int main(){
    solve();
return 0;
}