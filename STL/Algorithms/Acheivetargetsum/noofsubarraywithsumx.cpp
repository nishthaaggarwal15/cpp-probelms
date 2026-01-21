#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> prefixSum(n);
    for (int i = 0; i < n; i++) {
        cin >> prefixSum[i];
        if (i > 0)
            prefixSum[i] += prefixSum[i - 1];
    }

    int subarrayCount = 0;
    map<int, int> freq;

    freq[0] = 1;  

    for (int i = 0; i < n; i++) {
        subarrayCount += freq[prefixSum[i] - targetSum];
        freq[prefixSum[i]]++;
    }

    cout << subarrayCount << endl;
    return 0;
}
