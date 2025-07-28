// 3 sum when all elements are distinct 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int main(){
    int n ,t;
    cin>>n>> t;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>> arr[i];
    }
    sort(arr,arr+n);
    int count =0;
    for(int j =0; j<n; j++){
       int i =0; int k = n-1;
       while(i<j&& j<k){
        if(arr[i]+ arr[j]+ arr[k]==t){
       count++;
       i++; k--;
        } else if(arr[i]+arr[j]+arr[k]>t){ 
            k--;
        } else{
            i++;
        }
       }
    }
    return 0;
}