#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> e[N];
int n, ans;

int dfs(int u, int fa) {
	int d1 = 0, d2 = 0;
	
	for (auto p : e[u]) {
		int x = p.x, y = p.y;
	    if (x == fa) continue;
		int d = dfs(p.x, u) + y;
		if (d >= d1) {
			d2 = d1, d1 = d;
		}
		else if (d >= d2) d2 = d;
	}
	ans = max(ans, d1 + d2);
	return d1;
}

int main() {
	cin >> n;
	for (int i = 1;i < n;i ++ ) {
		int a, b, c; cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c}); 
	}	
	
	dfs(1, -1);
	cout << ans << endl;
}
