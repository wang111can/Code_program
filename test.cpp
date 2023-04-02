#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n = 2021041820210418, ans = 0;
	for (ll i = 1;i <= n;i ++ ) {
		for (ll j = 1;j <= n / i;j ++ ) {
			for (ll k = 1;k <= n / i / j;k ++ ) {
				if (i * j * k == n) ans ++ ;
			}
		}
	}
	cout << ans << endl;
}