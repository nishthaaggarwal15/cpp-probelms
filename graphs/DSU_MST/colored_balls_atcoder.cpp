#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<set<int>> st(n);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		st[i].insert(c);
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (st[a].size() < st[b].size()) {
			for (int i : st[a]) st[b].insert(i);
			st[a].clear();
			cout << st[b].size() << '\n';
		}
		else {
			for (int i : st[b]) st[a].insert(i);
			st[b].clear();
			cout << st[a].size() << '\n';
			swap(st[a], st[b]);
		}
	}
}
