/*
多重背包 优化 问题
f[0][0] = 1;
f[i][j] |= f[i][j - v]

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
bool f[N];
int v[N];

int main() {
    while (cin >> n >> m, n) {
        vector<int> a(n + 1), b(n + 1);
        int cnt = 0;
        for (int i = 1;i <= n;i ++ ) cin >> a[i];
        for (int i = 1;i <= n;i ++ ) cin >> b[i];
        
        for (int i = 1;i <= n;i ++ ) {
            int x = a[i], y = b[i], k = 1;
            // cout << x << ' ' << y << endl;
            while (k <= y) {
                v[++ cnt] = k * x;
                y -= k;
                k *= 2;
            }
            if (y > 0) {
                v[++ cnt] = x * y;
            }
        }
        n = cnt;
        f[0] = true;
        for (int i = 1;i <= n;i ++ ) {
            for (int j = m;j >= v[i];j -- ) {
                f[j] |= f[j - v[i]];
            }
        }
        int ans = 0;
        for (int i = 1;i <= m;i ++ ) ans += f[i];
        cout << ans << endl;

    
        memset(f, false, sizeof f);
        memset(v, 0, sizeof v);
    }
}