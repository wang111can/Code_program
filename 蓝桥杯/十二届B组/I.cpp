#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

pair<int, int> q[N];
int top, n, a[N], m;

int main() {
	cin >> n >> m;
	
	while (m -- ) {
		int op, x; cin >> op >> x;
		if (!op) {
			while (top && q[top].x == 0) x = max(x, q[top -- ].y);
			while (top >= 2 && q[top - 1].y <= x) top -= 2;
			q[++ top] = {op, x}; 
		}
		else if (top) {
			while (top && q[top].x == 1) x = min(x, q[top -- ].y);
			while (top >= 2 && q[top - 1].y >= x) top -= 2;
			q[++ top] = {op, x};
		}
	}
	
	int l = 1, r = n, k = n;
	for (int i = 1;i <= n;i ++ ) {
		if (!q[i].x) while (l <= r && q[i].y  < r) a[r -- ] = k -- ;
		else {
			while (l <= r && q[i].y > l) a[l ++ ] = k ++ ;
		}
	}
	if (top & 1) {
		while (l <= r) a[l ++ ] = k -= ;
	}
	else while (l <= r) a[r -- ] = k -- ;
	
	for (int i = 1;i <= n;i ++ ) cout << a[i] << ' ';
}
