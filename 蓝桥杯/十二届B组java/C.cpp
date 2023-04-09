#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;
using ll = long long ;


set<pair<double, double>> st;

int main() {
	for (int i = 0;i < 20;i ++ ) {
		for (int j = 0;j < 21;j ++ ) {
			for (int z = i + 1;z < 20;z ++ ) {
				for (int k = 0;k < 21;k ++ ) {
					double x = (j - k) * 1.0 / (i - z);
					double b = (k * i - j * z) * 1.0 / (z - i);
					st.insert({x, b});
				}
			}
		}
	}
	
	cout << st.size();
	return 0;
}

