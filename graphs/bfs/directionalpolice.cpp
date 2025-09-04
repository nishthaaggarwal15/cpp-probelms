/*
🔹 Problem Statement (in simple words)

We are given an n × m grid:

S = Starting position.

E = Exit position.

W = Wall (cannot pass through).

. = Empty cell.

U, R, D, L = Police facing Up, Right, Down, Left.

Rules:

Each police sees only in their assigned direction (until a wall or another police stops their view).

Any cell in a police’s line of sight becomes blocked (B).

We must check if it is possible to escape from S to E, and if yes, also output the shortest path.
*/
#include<bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define int         long long
#define pb          push_back
#define sz(v)       (int)(v.size())
#define f(i,a,b)    for(int i=a; i<b; i++)
#define F           first
#define S           second
#define MP          make_pair
using ii = pair<int,int>;
const int dx[]  = {-1,0,1,0}; // U R D L
const int dy[]  = {0,1,0,-1};
char dirchar[] = {'U','R','D','L'};
int n,m;
vector<string> arr;

bool isvalid(int x, int y){
 if(x<0 or y<0 or x>=n or y>=m or arr[x][y]=='W') return 0;
    else return 1;
}
void process(vector<ii>pos[]){
for(int dir =0; dir<4; dir++){
    for(auto v: pos[dir]){
      int x = v.F+dx[dir];
      int y = v.S+dy[dir];
      while(isvalid(x,y)&& arr[x][y]!=dirchar[dir]){ // hit another police of same direction
       arr[x][y]='B';
       x+= dx[dir];
       y += dy[dir]; // going in the curr direction like moving forward in right only not left or up and down
      }
    }
    for(auto v : pos[dir]) arr[v.F][v.S]='B';
}
}

int bfs(ii st, ii en, vector<vector<ii>>& par){
    vector<vector<int>> dis(n, vector<int>(m, 1e18));
    dis[st.F][st.S]=0;
    queue<ii> q;
    q.push(st);

    while(!q.empty()){
       ii cur = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int nx = cur.F+dx[k];
            int ny = cur.S+dy[k];
            if(!isvalid(nx,ny) || arr[nx][ny]=='B') continue;
            if(dis[nx][ny] > dis[cur.F][cur.S]+1){
                dis[nx][ny] = dis[cur.F][cur.S]+1;
                par[nx][ny] = cur;
                q.push({nx,ny});
            }
        }
    }
    return (dis[en.F][en.S]==1e18 ? -1 : dis[en.F][en.S]);
}
void solve(){
cin>>n>>m;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];

    ii st, en;
    vector<ii> pos[4];   // U R D L

    f(i,0,n){
        f(j,0,m){
            if(arr[i][j]=='S') st={i,j};
            else if(arr[i][j]=='E') en={i,j};
            else if(arr[i][j]=='U') pos[0].pb({i,j});
            else if(arr[i][j]=='R') pos[1].pb({i,j});
            else if(arr[i][j]=='D') pos[2].pb({i,j});
            else if(arr[i][j]=='L') pos[3].pb({i,j});
        }
    }

    process(pos);
        vector<vector<ii>> par(n, vector<ii>(m, MP(-1,-1)));// print path track parent
    int ans = bfs(st, en, par);
    if(ans!=-1){
       ii temp =en;
       vector<ii>path;
       while(temp!=st){
        path.push_back(temp);
        temp= par[temp.F][temp.S];
       }
 path.pb(st);
        reverse(path.begin(), path.end());

        for(auto i: path) cout << i.F << " " << i.S << endl;
    }
}
signed main(){    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   solve();
}
// logic was to mark the vision as blockd area and run normal bfs