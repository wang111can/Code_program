#include <bits/stdc++.h>

#define x first
#define y second

using ll = long long;
using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> e[N];
int n, cnt;

int dfs(int u, int fa) {
	
	int d1 = 0, d2 = 0;
	for (auto p : e[u]) {
		if (p.x == fa) continue;	
		int dis = dfs(p.x, u) + p.y;
		if (dis >= d1) {
			d2 = d1, d1 = dis;
		}
		else if (dis > d2) {
			d2 = dis;
		}
	}
	cnt = max(cnt ,d1 +d2);
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
	ll ans = 0;	
	for (int i = 1;i <= cnt;i ++ ) {
		ans += i + 10;
	}
	cout << ans << endl;

	
}
