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
// approach 1 : when we are not looking for order
// void rec(int level){
//     if(level==k){// number of knights placed and left are level
//         ans++;//no of ways
//         return;
//     }
// for(int i =0; i<n;i++){//choices
//     for(int j =0; j<n; j++){
//         if(check(i,j)){//check
//             board[i][j]=1;//move
//             rec(level+1);//recurse
//             board[i][j]=0;//backtrack


//         }
//     }
// }
// }

// appoach 2: when we are looking for order(look in notes)
void rec(int level, int px, int py){
    if(level==k){// number of knights placed and left are level
        ans++;//no of ways
        return;
    }
for(int i =0; i<n;i++){//choices
    for(int j =0; j<n; j++){
        if(i==px&& j>= py){
            continue;
        }
        if(check(i,j)){//check
            board[i][j]=1;//move
            rec(level+1,i,j);//recurse
            board[i][j]=0;//backtrack


        }
    }
}
}

int main(){
    cin>>n>>k;
    ans =0;
    // rec(0); // approach 1
    rec(0,0,-1);
    // for(int i =1; i<=k; i++) ans/=i;// approach 1 reason mentioned in notes
    cout<<ans<<endl;
    return 0;
}