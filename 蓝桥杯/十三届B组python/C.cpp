#include <bits/stdc++.h>

using namespace std;

int main() {
	int x = 1189, y = 841;
	string str; cin >> str;
	int k = str[1] - '0';
	while (k -- ) {
		if (x < y) swap(x, y);
		x /= 2;
	}
	cout << max(x, y) << ' ' << min(x, y) << endl;
} 
