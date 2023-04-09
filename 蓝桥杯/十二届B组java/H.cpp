#include <bits/stdc++.h>

using namespace std;

int a[100010];
int s[100010];
int ans[100010];

int main() {
	int n; cin >> n;
	for (int i = 1;i <=	n;i ++ ) {
		cin >> a[i];
	}
	int m; cin >> m;
	for (int i = 1;i <= m;i ++ ) {
		int l, r; cin >> l >> r;
		s[l] ++ , s[r + 1] -- ;
	}
	
	for (int i = 1;i <= n;i ++ ) {
		s[i] += s[i - 1];		
	}
	sort(s + 1, s + 1 + n);
	sort(a + 1, a + 1 + n);
	long long ans = 0;
	for (int i = 1;i <= n;i ++ ) {
		ans += 1ll * a[i] * s[i];
	} 
	cout << ans << endl;
		
}
