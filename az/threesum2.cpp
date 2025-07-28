// 3 sum when there might be duplicate element
#include<bits/stdc++.h>
using namespace std;
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
      int itemp =i;
      int ktemp =k;
      while(itemp<j && arr[itemp]==arr[i]){
        itemp++;
      } while(ktemp>j && arr[ktemp]==arr[k]){
        ktemp--;
      } 
      count+= (itemp-i)*(k-ktemp);// this will just temporaly move pointers and count number of duplicates and we can place original ones to that to skip br br same pairs ko count krna and for ans orignal pointers and temp pointers ka diff will result to their count
      i = itemp;
      k = ktemp;
      
        } else if(arr[i]+arr[j]+arr[k]>t){ 
            k--;
        } else{
            i++;
        }
       }
    }
    return 0;

}