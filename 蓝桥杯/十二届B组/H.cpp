#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 110, M = 100000;

int ans = 0x3f3f3f3f;
ll n = 5; 
ll op(ll x, ll c) {
	ll res = 1;
	for (int i = x, j = 1;j <= c;i -- , j ++ ) {
		res = res * i  / j;
		if  (res > n) return res;
	}
	return res;
}

bool check(ll x) {
	ll l = x * 2, r = max(l, n);  
	while (l < r) {
		ll mid = l + r >> 1; 
		if (op(mid, x) >= n)  r = mid;
		else l = mid + 1;
	}
//	cout << r << ' ' << l << endl;
	if (op(r, x) == n) {
		int cnt = r * (r + 1) / 2 + x + 1;
		cout << cnt << endl;
		return true;
	}
	return false;
	
}

int main() {
	cin >> n;	
	if (n == 1) cout << 1;
	else {
		
		for (int i = 16;i >= 0;i -- ) {
			if (check(i)) break;
		}
	}
}
