#include <bits/stdc++.h>

// f[i][0 / 1] °²ÅÅ ÈË

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx;
int f[N][2], n;


void add(int a, int b ){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa) {
	f[u][1] = 1;
	for (int i = h[u]; ~i;i = ne[i]) {
		int y = e[i];
		if (y == fa) continue;
		dfs(y, u);
		f[u][1] += min({f[y][0], f[y][1]}) ;
		f[u][0] += f[y][1];
	}
}

int main() {
	while (cin >> n) {
		vector<int> deg(n + 1, 0);
		memset(f, 0, sizeof f);
		memset(h, -1, sizeof h);
		idx = 0;
		for (int i = 1;i <= n;i ++ ) {
			int a, b, x;
			scanf("%d:(%d)", &a, &x);
			a ++ ;
			while (x -- ) {
				cin >> b;
				b ++ ;
				deg[b] ++ ;
				add(a, b);
			}
		}
		int root = 0;
		for (int i = 1;i <= n;i ++ ) {
			if (!deg[i]) root = i;
		}
		dfs(root, 0);
		cout << min(f[root][1], f[root][0]) << endl;
	}
} 
