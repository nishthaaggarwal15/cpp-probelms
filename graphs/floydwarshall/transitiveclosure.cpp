#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  INF 1e15
int n,m;

vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
void transitiveclosure(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j =1; j<=n ; j++){
                dist[i][j]= dist[i][j]|dist[i][k]&dist[k][j];
           }
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