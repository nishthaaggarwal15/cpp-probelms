#include<bits/stdc++.h>
using namespace std;
string p;
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
    cin>>p>>t;
   string w = p+ "#"+ t;
   vector<int> arr;
   
   arr = kmp(w);
   int ans =0;
   for(int i =p.size()+1; i<arr.size(); i++){
     if(arr[i]==p.size()){
      ans++;
     }
   }
   cout <<ans<<endl;
    return 0;
}