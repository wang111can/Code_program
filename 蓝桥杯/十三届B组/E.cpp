#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100010;

int a[N], b[N];
ll A, B, n, m1, m2, w[N], mul[N], mod = 1000000007;

int main() {
	cin >> n;
	cin >> m1;
	for (int i = m1; i;i -- ) cin >> a[i];
	cin >> m2;
	for (int i = m2; i;i -- ) cin >> b[i];
	
	int m = max(m1, m2);
	for (int i = m; i;i -- ) {
		w[i] = max({a[i] + 1, b[i] + 1, 2});
	}
    
    mul[1] = 1;
	for (int i = 2;i <= m;i ++ ) {
		mul[i] = mul[i - 1] * w[i - 1] % mod;
	}
	
	ll ans = 0; 
	for (int i = 1;i <= m;i ++ ) {
		A = (A + a[i] * mul[i]) % mod;
		B = (B + b[i] * mul[i]) % mod;
	}
	cout << (A - B + mod) % mod << endl;
	
}
