#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 1;i <= n;i ++ ) a[i - 1] = i;
	sort(a.begin(), a.end(), [&](int x, int y) {
		int x1 = 0, x2 = 0;
		int k1 = x, k2 = y;
		while (k1) {
			x1 += k1 % 10;
			k1 /= 10; 
		}
		while (k2) {
			x2 += k2 % 10;
			k2 /= 10;
		}
		if (x1 == x2) {
			return x < y;
		}
		return x1 < x2;
	});
	cout << a[m - 1];

} 
