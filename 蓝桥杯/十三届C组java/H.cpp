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

int main() {

	cin >> n >> x; x *= 2;
	for (int i = 1;i < n;i ++ )	 cin >> s[i], s[i] = s[i] + s[i - 1];
	ll l = 1, r = 100010;
	while (l < r) {
		ll mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << endl;


} 
