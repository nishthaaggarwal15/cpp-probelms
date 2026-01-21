#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // prefixSum -> list of indices where it appears
    unordered_map<int, vector<int>> prefixIndexMap;
    prefixIndexMap[0].push_back(-1);  // base case

    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int required = prefixSum - targetSum;

        if (prefixIndexMap.count(required)) {
            for (int startIndex : prefixIndexMap[required]) {
                // print subarray from startIndex+1 to i
                cout << "[ ";
                for (int k = startIndex + 1; k <= i; k++) {
                    cout << arr[k] << " ";
                }
                cout << "]\n";
            }
        }

        prefixIndexMap[prefixSum].push_back(i);
    }

    return 0;
}
