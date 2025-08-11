#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
using state = pair<int,int>;
#define pb push_back
#define endl '\n'
int n,m;
vector<vector<char>> arr;// characters to store grid
state st;//start of person
vector<vector<int>> dist_p; // dist of p from e
vector<state> mons; // mons pairs
vector<vector<int>> dist_m;// dist of m from e
vector<state> exits;//boundary cells of grid
int dx []= {-1,1,0,0};
int dy []= {0,0,-1,1};
bool isvalid(int x, int y){
if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='.') return true;
return false;   
}
void multibfs(){
    queue<state> q;
   for(auto it:mons) {
        q.push(it);
        dist_m[it.F][it.S] = 0;
    }
while(!q.empty()){
    int x = q.front().F;
    int y = q.front().S;
    q.pop();
    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(isvalid(nx,ny)){
            if(dist_m[nx][ny]> dist_m[x][y]+1){
                dist_m[nx][ny] = dist_m[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

}
void bfs(state node ){
queue<state> q;
q.push(node);
dist_p[node.F][node.S] = 0;
while(!q.empty()){
    int x = q.front().F; 
    int y = q.front().S;
    q.pop();
    for(int i =0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(isvalid(nx,ny)){
        if(dist_p[nx][ny]>dist_p[x][y]+1){
            dist_p[nx][ny] = dist_p[x][y]+1;
            q.push({nx,ny});
        }
    }
    }
}
}

void solve(){
 // Multisource BFS to compute minimum distance of any monster to boundary
    multibfs();

    // Plain BFS to compute minimum distance of any boundary cell to person
    bfs(st);
    // Check if distance of boundary cell from person is less than or equal to minimum distance of any monster to boundary
for(auto v: exits){
    if(dist_p[v.F][v.S]<=dist_m[v.F][v.S]){
        cout<<"YES";
        return;
    }
}
cout<<"NO"<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    arr.resize(n,vector<char>(m));
    for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
        cin>>arr[i][j];
        if(arr[i][j]=='A'){
        st= {i,j};
        if(i==0 || j==0|| j==m-1||i==n-1){
           exits.pb({i,j});
        } 
        } else if(arr[i][j]=='M'){
            mons.pb({i,j});
        } else if(i==0|| j==0|| j==m-1|| i==n-1){
            exits.pb({i,j});
        }
    }
    }
    dist_m.assign(n,vector<int>(m,1e9));
    dist_p.assign(n,vector<int>(m,1e9));
solve();
    return 0;
}