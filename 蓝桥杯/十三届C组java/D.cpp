#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll s[200010];

int main() {
	ll ans = 0;
	ll n; cin >> n;
	for (ll i = 1;i <= n;i ++ ) {
		cin >> s[i];
		s[i] = s[i - 1] + s[i]; 
	}
	for (int i = 1;i <= n;i ++ ) {
		ans += (s[i] - s[i - 1]) * (s[n] - s[i]);
	}
	cout << ans << endl;
}
 
