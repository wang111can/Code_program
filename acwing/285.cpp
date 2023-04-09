#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// f[i][0 / 1] 表示 i 去不去 
int f[N][2], n, w[N];
vector<int> e[N];
int deg[N];

void dfs(int u) {
	f[u][1] = w[u];
	for (auto x : e[u]) {
		dfs(x);
		f[u][1] += f[x][0];
		f[u][0] += max(f[x][1], f[x][0]);
	}
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i ++ ) cin >> w[i];
	for (int i = 1;i < n;i ++ ) {
		int a, b; cin >> b >> a;
		e[a].push_back(b);
		deg[b] ++ ;
	}
	
	int root = 0;
	for (int i = 1;i <= n;i ++ ) {
		if (!deg[i]) {
			root = i;
		}
	}	
	dfs(root);
	cout << max(f[root][0], f[root][1]);
}
