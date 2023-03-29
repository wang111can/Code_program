#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int a[N];
int n;
ll ans = -1e18, deep = 0;

int main() {
	cin >> n;
	for (int i = 1;i <= n;i ++ ) cin >> a[i];
	
	for (int i = 1, d = 1; i <= n;i *= 2, d ++ ) {
		ll sum = 0;		
		for (int j = i;j < i + (1 << d - 1) && j <= n;j ++ ) {
			sum += a[j];
		}
		if (sum > ans) {
			ans = sum, deep = d;
		}
	}
	cout << deep << endl;
	return 0;
} 
