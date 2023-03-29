/*
f[i][j] 表示 第 i 个 分神 使用 了 j 个查克拉
分为 2 个集合

最小值 == 0 
f[i][j] += f[i - 1][j] 第 i 个 影分身 的 查克拉 为 0 
最小值 > 0
f[i][j] 我们 把 每个人 的 查克拉 -1 方案 数 与 不减相同 
f[i][j] += f[i][j - i]

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while (t -- ) {
		int n, m; cin >> m >> n;
		vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
		f[0][0] = 1;
		for (int i = 1;i <= n;i ++ ) {
			for (int j = 0;j <= m;j ++ ) {
				f[i][j] += f[i - 1][j];
				if (j - i >= 0) {
					f[i][j] += f[i][j - i];
				}
			}
		}
		cout << f[n][m] << endl;
	}
	
}
