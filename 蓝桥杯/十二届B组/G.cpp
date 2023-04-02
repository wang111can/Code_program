#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 110, M = 100000;

int f[N][200010];
int a[N], n;

int main() {
	cin >> n;
	ll sum = 0;
	for (int i = 1;i <= n;i ++ ) {
		cin >> a[i];
		sum += a[i];
	}
	f[0][M] = 1;
	for (int i = 1;i <= n;i ++ ) {
		for (int j = -sum;j <= sum;j ++ ) {
		    f[i][j + M] |= f[i - 1][j + M];
			if (j - a[i] >= -sum) {
				f[i][j + M] |= f[i - 1][j - a[i] + M];
			}
			if (j + a[i]  <= sum) {
				f[i][j + M] |= f[i - 1][j + a[i] + M];
			}
		}
	}	
	
	ll ans = 0;
	for (int i = 1;i <= sum;i ++ ) {
		if (f[n][i + M]) ans ++ ;
	}
	cout << ans << endl;
	

}
