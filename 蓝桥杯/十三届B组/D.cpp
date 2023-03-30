#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100010;

int a[N], n, ans[N];

int main() {
	cin >> n;
	for (int i = 1;i <= n;i ++ ) {
		ans[i] = max(n - i, i - 1) * 2;
	}
	for (int i = 1;i <= n;i ++ ) cout << ans[i] << endl;
	
	return 0;
}
