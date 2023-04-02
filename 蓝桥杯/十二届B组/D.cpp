#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n = 2021041820210418, ans = 0;
	vector<ll> primes;
	for (ll i = 1;i <= sqrt(n);i ++ ) {
		if (n % i == 0){
			primes.push_back(i);
			if (i * i != n) {
				primes.push_back(n / i);
			}
		}
	} 
//	cout << primes.size() << endl;
	for (auto i : primes) {
		for (auto j : primes) {
			for (auto z : primes) {
				if (i * j * z == n) ans ++ ;
			}
		}
	}
	cout << ans << endl;
}
