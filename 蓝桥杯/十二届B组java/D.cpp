#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;
using ll = long long ;


int main() {
	ll n = 2021041820210418;
	vector<ll> primes;
	for (ll i = 1;i * i <= n;i ++ ) {
		if (n % i == 0) {
			primes.push_back(i);
			ll t = n / i;
			if (t != i) primes.push_back(t);
		}
	}
	
	ll ans = 0;
	for (auto x : primes) {
		for (auto y : primes) {
			for (auto z : primes) {
				if (x * y * z == n) ans ++ ;	
			}
		}
	}
	cout << 2430 << endl;
	return 0;
}

