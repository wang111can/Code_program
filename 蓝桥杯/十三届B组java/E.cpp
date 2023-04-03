#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int a[N], b[N], n; 

int main() {
	ll k; cin >> k;
	
	ll l = 5, r = 5e18;
	function<ll(ll)> check = [&](ll x) {
		ll cnt = 0;
		while (x) cnt += x / 5, x /= 5;
		return cnt;
	};
	while (l < r) {
		ll mid = l + r >> 1;
		if (check(mid) >= k) r = mid;
		else l = mid + 1;
	}
	
  if (check(r) != k) cout << -1;
	else cout << r << endl;

	 
	return 0;
}
