#include<bits/stdc++.h>
using namespace std;

 string t;

vector<int> kmp(string s){
    int n = s.length();
    vector<int> kmp(n + 1);
    int i =0, j=-1; kmp[0]=-1;
    while(i<n){
while(j!=-1 && s[i]!=s[j])j= kmp[j];
j++;i++;
kmp[i]=j;
    }
    return kmp;
}
int main(){
    cin>>t;
      
    string w = t;      
    vector<int> arr = kmp(w);

    int n = t.size();
    int extperiod = t.size() - arr[n];
    int period ;
   if(n%(n-arr[n])==0){
period = n-arr[n];
   } else{
    period=n;
   }
   cout<<period<<endl;
   cout <<extperiod<<endl;
    return 0;
}