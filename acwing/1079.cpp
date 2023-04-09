#include <bits/stdc++.h>

using namespace std ;
	
const int N = 1e5 + 10, inf = 1e8;

vector<int> e[N];
int c[N], n, m;
int f[N][5];

void dfs(int u, int fa) {

	if (u <= n) return;
	f[u][0] = f[u][1] = 1;
	for (auto x : e[u]) {
		if (x == fa) continue;
		dfs(x, u);
		f[u][0] += min(f[x][0] - 1, f[x][1]);
		f[u][1] += min(f[x][1] - 1, f[x][0]);
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1;i <= n;i ++ ) cin >> c[i];
    for (int i = 1;i <= n;i ++ ) f[i][!c[i]] = inf, f[i][c[i]] = 1;
	for (int i = 0;i < m - 1;i ++ ) {
		int a, b; cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(n + 1, -1);
	cout << min(f[n + 1][0], f[n + 1][1]);
	

}
