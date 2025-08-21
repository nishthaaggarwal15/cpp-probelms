#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  INF 1e15
int n,m;
vector<vector<int>>parent(n+1,vector<int>(n+1,0));
vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
void floydforpath(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j =1; j<=n ; j++){
          if(dist[i][k]>dist[i][k]+dist[k][j]){
            dist[i][j]= dist[i][k]+dist[k][j];
            parent[i][j]= parent[k][j];
          }
            }
        }
    }

}
void printpath(int i, int j){
    if(i!=j)printpath(i,parent[i][j]);
    cout<<j<<"\n";
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