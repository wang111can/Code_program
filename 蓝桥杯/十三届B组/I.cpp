#include <bits/stdc++.h>

using namespace std;

const int N = 110, mod = 1000000007;

int f[N][N][N];

int main() {
	int n, m; cin >> n >> m;
	f[2][0][0] = 1;

		for (int j = 0;j <= n;j ++ ) {
			for (int k = 0;k <= m;k ++) {
			    for (int i = 0;i <= m;i ++ ) {
				if (i % 2 == 0 && j) {
					f[i][j][k] = (f[i][j][k] + f[i / 2][j - 1][k]) % mod;
				}
				if (k) {
					f[i][j][k] = (f[i][j][k] + f[i + 1][j][k - 1]) % mod;
				}
			} 
		}
	}
	cout << f[1][n][m - 1] << endl;
	
} 
