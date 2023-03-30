#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int tr[N], n, a[N];
int f[N];
inline int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	for (;x <= n;x += lowbit(x)) tr[x] = max(tr[x], y);
}

int ask(int x) {
	int res = 0;
	for (; x;x -= lowbit(x)) res = max(res, tr[x]);
	return res;
}




int main() {
	cin.tie(0), cout.tie(0);
	cin >> n;
	int ans = 0;
	vector<int> vx;	
	for (int i = 1;i <= n;i ++ ) {
		cin >> a[i];
		vx.push_back(a[i]);
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	for (int i = 1;i <= n;i ++ ) {
	    f[i] = 1;
	    int x = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin() + 1;
	    f[i] = max(f[i], ask(x - 1) + 1);
        add(x, f[i]);
	}
	cout << *max_element(f + 1, f + 1 + n) << endl;
	
}
