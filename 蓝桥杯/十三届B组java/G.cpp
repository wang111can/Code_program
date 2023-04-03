#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int f[N], a[N], n, mod = 1000000007;

int main() {
	cin >> n;
	f[0] = 1;
	for (int i = 1;i <= n;i ++ ) cin >> a[i];
	for (int l = 1;l <= n;l ++ ) {
		int minv = 1e9, maxv = -1e9; 
		for (int r = l;r <= n;r ++ ) {
			minv = min(minv, a[r]), maxv = max(maxv, a[r]);
			if (r - l == maxv - minv) {
				f[r] = (f[r] + f[l - 1]) % mod;
			}
		}
	}
	cout << f[n];
}
