#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int a[N], b[N], n; 

int main() {
	cin >> n;
	for (int i = 1;i <= n;i ++ ) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1;i <= n;i ++ ) {
		int l = lower_bound(b + 1, b + 1 + n, a[i]) - b;
		int r = upper_bound(b + 1, b + 1 + n, a[i]) - b - 1;
		int left = l - 1, right = n - r;
		if (right > left) {
			int k = b[right + right - left - 1];
			a[i] = k - a[i];
		}
		else {
			a[i] = 0;
		}
		 
		
	}
	for (int i = 1;i <= n;i ++ ) cout << a[i] << ' ';
	return 0;
}
