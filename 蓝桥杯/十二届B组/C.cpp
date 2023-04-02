#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	set<pair<double, double>> st;
	for (int i = 0;i < 20;i ++ ) {
		for (int j = 0;j < 21;j ++ ) {
			for (int x = i + 1;x < 20;x ++ ) {
				for (int y = 0;y < 21;y ++ ) {
					double k = (y - j) * 1.0 / (x - i);
					double b = (y * i - j * x) * 1.0 / (x - i);
					st.insert({k, b});
				}
			}
		}
	}
	cout << st.size() + 20<< endl;

}
