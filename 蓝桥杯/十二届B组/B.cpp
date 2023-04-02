#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int a[] = {2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021, 2021};
	for (int i = 1; ;i ++ ) {
		int n = i;
		while (n) {
			if (a[n % 10] == 0) {
				cout << i - 1 << endl;
				return 0;
			}
			a[n % 10] -- ;
			n /= 10;
		}
 	}
 	

}
