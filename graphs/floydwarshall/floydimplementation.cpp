#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  INF 1e15
int n,m;
vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
void floydwarshal(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j =1; j<=n ; j++){
          if(dist[i][k]<INF && dist[k][j]<INF){
            dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);
          }
            }
        }
    }

}
bool checknegcycle(){
    for(int i =1; i<=n; i++){
        if(dist[i][i]<0) return true;
    }
    return false;
}
void printdist(){
    for(int i =1; i<=n; i++){
        for(int j=1; j<=m; j++){
        if(dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)dist[i][i]=0;
    for(int i=0; i<m; i++){
        int a,b; ll c;
         cin>>a>>b>>c;
         dist[a][b]= min(dist[a][b],c);// in case of multiple edges
    }
    return 0;
}