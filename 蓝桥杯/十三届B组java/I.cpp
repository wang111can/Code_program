#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1010;

ll f[N][N];
ll n, m, v, k;
int main() {
	// f[i][j] 表示 走过 第 i 个 点 氮气 的 充能时间 
	// f[i][0] = min(f[i - 1][0], f[i - 1][1]) + 
	for (int i = 0;i < 1010;i ++ ) {
	    for (int j = 0;j < 1010;j ++ ) {
	        f[i][j] = 1e18;
	    }
	}
	cin >> n >> m >> k >> v;
	for (int i = 0;i < k;i ++ ) {
		f[0][i] = 0;
	}
	m ++ ;
	//从 第 i - 1 到 第 i 个 红绿灯 的 消耗 时间 为 (w[i][0] - w[i - 1][0]) * v // 不需要 等 红灯
	// k = f[i][j] // 表示 消耗 时间
	// f[i][k - 1] = f[i - 1][0]  使用 光速 行驶
	// f[i][k] = min(f[i][k], f[i - 1][k + 1]  
	// time = w[i][1] + w[i][2] // 为 红绿 灯 周期
	// 当 f[i][j] % times >= w[i][1] 时  大于 绿灯 持续 时间 
	// f[i][j] += time - f[i][j] % times 加上 等待 时间 
	vector<array<ll, 3>> w(m + 1, {0, 0, 0});
	for (int i = 1;i <= m - 1;i ++ ) {
		ll a, b, c; cin >> a >> b >> c;
		w[i] = {a, b, c};
	}
	w[m] = {n, 1, 0};
	
	for (int i = 1;i <= m;i ++ ) {  
	    f[i][k - 1] = f[i - 1][0];
	    if (f[i][k - 1] % (w[i][1] + w[i][2]) >= w[i][1]) {
	        f[i][k - 1] += w[i][1] + w[i][2] - f[i][k - 1] % (w[i][1] + w[i][2]);
	    }
	    for (int j = -1;j < k - 1;j ++ ) {
	        if (f[i - 1][j + 1] != 0x3f3f3f3f) { // 能 转移
	            ll t = f[i - 1][j + 1] + 1ll * (w[i][0] - w[i - 1][0]) * v;
	            if (t % (w[i][1] + w[i][2]) >= w[i][1]) {
	                t += w[i][1] + w[i][2] - t % (w[i][1] + w[i][2]);
	            }
	            // f[i][0] 可以 由 f[i - 1][0] f[i - 1][1] 转移
	            f[i][max(0, j)] = min(f[i][max(0, j)], t);
	           }
	    }
	}
    ll ans = 1e18;
    for (int i = 0;i < k;i ++ ) ans = min(ans, f[m][i]);
    cout << ans << endl;
}