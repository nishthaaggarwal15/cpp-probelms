#include<bits/stdc++.h>
using namespace std;
int n,k; 
int ans =0; 
int board[14][14];
int dx[]= {1,2,2,1,-1,-2,-2,-1};
int dy[]= {2,1,-1,-2,-2,-1,1,2};
bool check(int i, int j){
if(board[i][j]==1) return;
for(int pos = 0; pos<8; pos++){
    int nx = i+dx[pos];
    int ny = i+dy[pos];
    //nx ny cells are getting attacked
    if(nx>=0 && nx<n && ny>=0&& ny<n && board[nx][ny]==1)return 0;
}
return 1;
}

void rec(int level,int knights){
    if(level==n*n){
        if(knights==0)
        ans++;
        return;
    }
    int row = level/n;
    int col = level%n;
    
//dont place a knight
rec(level+1, knights);
// place a knight
if(knights>0 && check(row,col)){
    board[row][col]=1;
    rec(level+1, knights-1);   
    board[row][col]=0;
}

}

int main(){
    cin>>n>>k;
    ans =0;
    
    rec(0,0,-1);

    cout<<ans<<endl;
    return 0;
}