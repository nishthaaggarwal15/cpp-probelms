#include<bits/stdc++.h>
using namespace std;
const int N =100005;
const int LOG =20;
int up[N][LOG];// up[v][j]= 2^jth next of v
int n,q;

void preprocess(vector<int>& nxt){
for(int i =1; i<=n; i++){
    up[i][0]= nxt[i];
}
for(int j =1; j<LOG; j++){
    for(int i=1;i<=n; i++){
        if(up[i][j-1]!=-1){
            up[i][j]= up[up[i][j-1]][j-1];
        } else{
            up[i][j]=-1;
        }
    }
}
}
int kthelement(int x, int k){
    for(int j =0; j<LOG; j++){
        if(k &(1<<j)){
            x=up[x][j];
            if(x==-1) return -1;
        }
    }
    return x;
}
int main(){
    cin>>n>>q;
vector<int> nxt(n+1);
for(int i =1; i<=n; i++){
    cin>>nxt[i];
}
preprocess(nxt);
while(q--){
    int x,k;
    cin>>x>>k;
    cout<<kthelement(x,k)<<"\n";
}
    return 0;
}