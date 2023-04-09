#include <bits/stdc++.h>

using namespace std;

const int N = 1e5  + 10;

int f[N][5];

int main() {
	int T; cin >> T;
	f[0][0] = 1;
	for (int i = 1;i * i < N;i ++ ) {
		for (int j = i * i;j < N;j ++ ) {
			for (int k = 1;k <= 4;k ++ ) {
				f[j][k] += f[j - i* i][k - 1];
			}
		}
	}
	while (T -- ) {
		int n; cin >> n;

		int ans = 0;
		for (int i = 1;i <= 4;i ++ ) ans += f[n][i];
		cout << ans << endl;
	}
}
