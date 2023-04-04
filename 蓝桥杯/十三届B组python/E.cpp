#include <bits/stdc++.h>

using namespace std;

int main() {

	
	int dx[] = {0, -1, -1, 0, 1, 1}, dy[] = {-1, 0, 1, 1, 0, -1};
	int x1[2], x2[2];
	for (int i = 0;i <= 1;i ++ ) {
		int a, b, c; cin >> a >> b >> c;
		int x = 0, y = 0;
		x += dx[a] * b, y += dy[a] * b;
		a = (a + 2) % 6;
		x += dx[a] * c, y += dy[a] * c;
		cout << x << ' ' << y << endl; 
		x1[i] = x, x2[i] = y;
	}
//	cout << abs(x1[0] - x2[0] + x)

} 
