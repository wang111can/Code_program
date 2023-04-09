#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll n, ans, w[N], f[N];
vector<ll> e[N];

ll dfs(int u, int fa) {
	f[u] = w[u];
	for (auto x : e[u]) {
		if (x == fa) continue;
		dfs(x, u);
		f[u] += max(0ll, f[x]);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i ++ ) cin >> w[i];
	for (int i = 1;i < n;i ++ ) {
		int a, b; cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, -1);
    cout << *max_element(f + 1, f + 1 + n);

}
