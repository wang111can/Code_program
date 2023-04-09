#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int a[10];

int main() {
	for (int i = 0;i < 10;i ++ ) a[i] = 2021;
	for (int i = 1; ;i ++ ) {
		int n = i;
		while (n) {
			if (a[n % 10] == 0) {
				cout << i << endl;
				return 0;
			}
			a[n % 10] -- ;
			n /= 10;
		}
	}
	
	return 0;
}

