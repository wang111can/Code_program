#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 998244353;

int main() {
	ll n; cin >> n;
	ll ans = 1;
	for (int i = n;i > 2;i -- ) {
		ans = ans * i % mod;
	}	
	ans = ans * (n * (n - 1) / 2 % mod) % mod  % mod;
	cout << ans << endl;
}
