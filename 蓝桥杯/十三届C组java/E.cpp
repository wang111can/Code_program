#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

array<int, 2> a[3];


int check(int x, int y, int z) {
					// cout << x << ' ' << y << ' ' << z << endl;
  int res = 8;
	for (int i = 0;i < 2;i ++ ) {
		for (int j = 0;j < 2;j ++ ) {
			for (int k = 0;k < 2;k ++ ) {
				// if (x == 1 && y == 2 && z == 0) {
				// 	cout << i << ' ' << j << ' ' << k << endl;
				// 	cout << a[x][i] << '+' << a[y][j] << '=' << a[z][k] << endl;
				// 	cout << a[x][!i] << '=' << a[y][!j] << endl;
				// 	cout << endl;
				// }
      
				if (a[x][i] == a[y][j] && a[y][j] == a[z][k]) res = min(res, 4);
				if (a[x][i] + a[y][j] == a[z][k]) {
					if (a[x][!i] == a[y][!j]) res = min(res, 4);
					res = min(res, 6);
				}
        if (a[x][i] == a[y][j] || a[x][i] == a[z][k] || a[z][k] == a[x][i]) res = min(res, 6);

			}
		}
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t -- ) {
		for (int i = 0;i < 3;i ++ ) {
			cin >> a[i][0] >> a[i][1];
		}

 		int ans = 8;
 		for (int i = 0;i < 3;i ++ ) {
 			for (int j = 0;j < 3;j ++ ) {
 				for (int z = 0;z < 3;z ++ ) {
 					if (j == i || j == z || z == i) continue;
					ans = min(ans, check(i, j, z));
				}
			 }
		 }
		 cout << ans << endl;
		
	}

}

