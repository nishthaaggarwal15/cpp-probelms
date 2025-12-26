#include<bits/stdc++.h>
using namespace std;
int n;
int arr[101];
int dp[101];
void solve(){
    int ans = -1e9;
for(int level=0; level<n; level++){
    if(level==0){
        dp[level]=arr[level];
    }else{
ans = max(ans,dp[level-1]+arr[level]);
    }
    ans = max(ans, dp[level]);
} 
cout<< ans<<endl;
}
int main(){
    return 0;
}



// for lesser memory space
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[101];

void solve(){
    int ans = -1e9;
    int last = -1e9;
for(int level=0; level<n; level++){
    if(level==0){
       last=arr[level];
    }else{
last = max(arr[level],last+arr[level]);
    }
    ans = max(ans, last);
} 
cout<< ans<<endl;
}
int main(){
    return 0;
}