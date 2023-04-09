#include <bits/stdc++.h>

using namespace std;

int f[110][110], n, k, a[110];

int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i ++ ) {
		cin >> a[i];
	}
	for (int i = 0;i < 110;i ++ ) {
	    for (int j = 0;j < 110;j ++ ) {
	        f[i][j] = -1e9;
	    }
	}
	f[0][0] = 0;
	for (int i = 1;i <= n;i ++ ) {
		for (int j = 0;j < k;j ++ ) {
			f[i][j] = f[i - 1][j];
			f[i][j] = max(f[i - 1][((j - a[i]) % k + k) % k] + a[i], f[i][j]);
		}
	}
	cout << f[n][0] << endl;
	
}
