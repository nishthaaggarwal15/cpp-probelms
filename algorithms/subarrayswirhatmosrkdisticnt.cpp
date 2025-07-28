#include <bits/stdc++.h>
using namespace std;
#define int long long
 map<int, int> m;
    int n, k;
 int arr[n];
          
int getsubarraylessthankdistinct(){// this is for >=k
    //but if we want <=k so we do all subarrays - subarrayswithatmostk-1
            // nc2-  atmostk
            // and for exactly k
            // we do subarray with atmost k - atmost k-1  
int head = -1, tail = 0;
        int ans = 0;
        int count = 0;

        while (tail < n) {
            while (head + 1 < n && (count < k || m[arr[head + 1]] > 0)) {
                head++;
                if (m[arr[head]] == 0) {
                    count++;
                }
                m[arr[head]]++;
            }
            ans+= (head-tail)+1;
          //this is for sum of length of all subarrays because 
          //we had number of subararays = length of longest subarray as mentioned in notes
          //so length of all subararys = 1+ 2+ 3 +4...n
          //so we'll do ap formulae n*n+1/2;
        //   int len = (head - tail + 1);
        //    ans+= len*(len+1)/2 
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                m[arr[tail]]--;
                if (m[arr[tail]] == 0) {
                    count--;
                }
                tail++;
            }
        }

      return ans;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
     
        cin >> n >> k;
      
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

       
    return 0;
}
