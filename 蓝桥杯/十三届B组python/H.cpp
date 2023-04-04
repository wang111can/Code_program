#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 998244353;

int main() {
	
	int n, m; cin >> n >> m;
	ll ans = 0;
	
	priority_queue<pair<int, int>> q;
	for (int i = 1;i <= n;i ++ ) {
		int a, b; cin >> a >> b;
		q.push({a, b});
	}
	while (m --  && q.size()) {
		while (q.top().first <= 0 && q.size()) q.pop();
		if (q.size()) {
			pair<int, int> t = q.top(); q.pop();
			ans += t.first;
			t.first -= t.second;
			q.push(t);
		}
	}
	cout << ans << endl;

}
