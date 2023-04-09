#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[100010];
int pos[N], f[N];
int n, m, s;

int main() {
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i ++ ) {
		cin >> a[i];
		f[i] = pos[a[i] ^ s];
		pos[a[i]] = i;
	}
	while (m -- ) {
		int l, r; cin >> l >> r;
			}
}
 
