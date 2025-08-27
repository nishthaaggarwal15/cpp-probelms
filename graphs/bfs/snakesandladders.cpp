#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>g;
using state = pair<int,int>;
#define F first 
#define S second
#define INF 1e9
vector<vector<int>>dist;
state getcoord(int s){
int quot= (s-1)/n;
int rem = (s-1)%n;
int row = n-1-quot;
int col = (quot%2==0)? rem : (n-1-rem);
return {row,col};
}
// int getsquare(int row, int col){
//     int quot = n-1-row;
//     int base = n* quot;
//     if(quot%2==0) return base +col+1;
//     return base+(n-1-col)+1;
// }
int bfs(){
  vector<int> dist(n*n + 1, INT_MAX);
    queue<int> q;
dist[1]=0;
q.push(1);
while(!q.empty()){
  int s = q.front();
    q.pop();
    if(s==n*n) return dist[s];
for(int i =1; i<=6;i++){
    int next = s+i;
    if(next>n*n) break;
state st = getcoord(next);
int r = st.F;
int c= st.S;
if(g[r][c]!=-1) next = g[r][c];
if(dist[next]== INT_MAX){
dist[next] = dist[s]+1;
q.push(next);
}
   }
    }
return -1;
}


void solve(){
    cin>>n;
    g.resize(n,vector<int>(n,-1));
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
        }
    }
    cout << bfs() << "\n";

}
int main(){
    solve();
    return 0;
}