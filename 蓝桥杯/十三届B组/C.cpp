#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll a, b, n; cin >> a >> b >> n;
	ll x = a * 5 + b * 2;
	ll k = n / x, t = n % x;
	ll ans = k * 7;
	if (t > a * 5) {
		ans += 5;
		t -= a * 5;
		while (t > 0) {
			ans ++ ;
			t -= b;
		}
	}
	else {
		while (t > 0) {
			ans ++ ;
			t -= a;
		}
	}
	cout << ans << endl;
	
}
