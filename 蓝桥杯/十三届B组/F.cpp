#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 10;

ll g[N][N], n, k, m;

int main() {
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i ++ ) {
		for (int j = 1;j <= m;j ++ ) {
			cin >> g[i][j];
		}
	}
	

	for (int i = 1;i <= n;i ++ ) {
		for (int j = 1;j <= m;j ++ ) {
            g[i][j] = g[i - 1][j]  + g[i][j];
		}
	}
	
	
	ll ans = 0;
	for (int i = 1;i <= n;i ++ ) {
		for (int j = i;j <= n;j ++ ) {
			ll sum = 0;
			for (int r = 1, l = 1;r <= m;r ++ ) {
                sum += g[j][r] - g[i - 1][r];
                while (sum > k)
                {
                    sum -= g[j][l] - g[i - 1][l];
                    l ++ ;
                }
                ans += r - l + 1;
			}
		} 
	}
	cout << ans << endl;
}
