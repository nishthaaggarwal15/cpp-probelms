#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        while (q--) {
            int t, x;
            cin >> t >> x;

            if (t == 1) {
                // smallest element >= x
                auto it = lower_bound(a.begin(), a.end(), x);
                if (it == a.end()) cout << -1 << " ";
                else cout << *it << " ";
            }
            else if (t == 2) {
                // smallest element > x
                auto it = upper_bound(a.begin(), a.end(), x);
                if (it == a.end()) cout << -1 << " ";
                else cout << *it << " ";
            }
            else if (t == 3) {
                // number of elements <= x
                int cnt = upper_bound(a.begin(), a.end(), x) - a.begin();
                cout << cnt << " ";
            }
            else if (t == 4) {
                // number of elements < x
                int cnt = lower_bound(a.begin(), a.end(), x) - a.begin();
                cout << cnt << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
