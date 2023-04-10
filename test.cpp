#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//
ll s[10010];
ll n, x;

bool check(ll k) {
	for (int i = n;i - k >= 1;i -- ) {
		if (s[i] - s[i - k - 1] < 2 * x) return false;
	}
	return true;
}

int main() {

	cin >> n >> x;
	for (int i = 1;i < n;i ++ )	 cin >> s[i], s[i] = s[i] + s[i - 1];
	ll l = 1, r = n + 1;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << endl;


} 