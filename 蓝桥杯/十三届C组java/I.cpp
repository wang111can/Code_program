#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s[100010];
ll n, x;

bool check(ll k) {
	for (int i = 1;i + k - 1 < n;i ++ ) {
		if (s[i + k - 1] - s[i - 1] < x) return false;
	}
	return true;
}

ll mod = 1e9 + 7;

ll work(ll k) {
	ll res = 0;
	for (int i = 1;i * i <= k;i ++ ) {
		if (k % i == 0) {
			res = (res + i * i % mod) % mod;
			ll t = k / i;
			if (t != i) {
				res = (res + t * t % mod) % mod;
			}
		}
	}
	return res;
}

int main() {
	cin >> n; ll res = 0;
	for (ll i = 1;i <= n;i ++ ) {
		res += work(i);
		res %= mod;
	}
	cout << res % mod;	


} 
