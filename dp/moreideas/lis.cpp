#include<bits/stdc++.h>
using namespace std;
int arr[1001];
int n;
vector<int>lis;
int insertedat[101];
int solve(){
for(int i =0; i<n; i++){
if(lis.size()==0 || lis.back()<arr[i]){
    lis.push_back(arr[i]);// if this elemeent is greater than last one we can extend the lis
    insertedat[i]=lis.size();
} else{
    // if this is smaller than find exactly bigger than and replace that with this one
    auto it= lower_bound(lis.begin(), lis.end(),arr[i]);
    *it = arr[i];
    insertedat[i]= it-lis.begin()+1;
}
}
for(int i=0;i<n;i++){
        //cout<<length[i]<<" "; // i the element par jo element haaa wo kaha par wo kis lenghtr par haa
    }
    int curlen=lis.size();
    vector<int>subseq;
    for(int i=n-1;i>=0;i--){
        if(insertedat[i]==curlen){
           subseq.push_back(arr[i]);
           curlen--;
        }
    }


    reverse(subseq.begin(),subseq.end());


    for(auto &x:subseq) cout<<x<<" ";

}
int main(){
    return 0;
}