#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

const int N = 3000;

int main() {
	ll n; cin >> n;
	n /= 1000;
	ll day = 0, h = 0, m = 0, s = 0;
	day = n / 60 / 60 / 24;
	h = n / 60 / 60 - day * 24;
	m = n / 60 - (h + day * 24) * 60;
	s = n - ((h + day * 24) * 60 + m) * 60;
	printf("%02d:%02d:%02d", h, m, s);
}
