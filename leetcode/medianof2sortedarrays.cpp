#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100100];
int b[100100];
bool check(int mid, int k){
// if # elements <=mid >=k then it is the median
int cnt1 = upper_bound(a, a+n, mid)-a; //no of elements smaller than equal to mid
int cnt2 = upper_bound(b, b+m, mid)-b; //no of elements smaller than equal to mid
return cnt1+cnt2 >=k;
}
int gethkth(int k ){
    int low = min(a[0], b[0] ); int high = max(a[n-1], b[m-1]);
    int ans = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(mid,k)){
            ans = mid;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
     for(int i =0; i<n; i++){
        cin>>b[i];
    }
    if(n%m==1){
     cout<<   gethkth((n+m)/2+1)<<endl;
    } else{
        cout<<(gethkth((n+m)/2) + gethkth((n+m)/2+1))/2.0<<endl;
    }
}
int main(){

}