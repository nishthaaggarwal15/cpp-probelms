// count longest subarray containg at least after flipping atleast k 0's to 1 
// array consist of only 1 and 0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; int k;
    int arr[n];
int head = -1;
int tail =0;
int countzero =0; 
int  ans = 0;
while(tail<n){ /// O(n)
    while(head+1<n&& arr[head+1]==1 || countzero <k ){// when we can eat next numbers  .... O(1) beacuse we have if condition i while
head++;
if(arr[head]==0) countzero++;
    } 
    ans = max(ans, head-tail+1);
    // when we have 0 elements in window k =0
    if(tail>head){ // O(n)
        tail++;
        head = tail-1;
    }
    // when we are moving forward and we have more 0 than we need so westore that length and remove 0 and proceed with next one
    else{ //O(n)
        if(arr[tail]==0) countzero--;
        tail++;
    }
    }
        return 0;
}


