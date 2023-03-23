#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f[250][250];
ll a[250], n;

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i]; a[i + n] = a[i];
    }

    for (int len = 2;len <= n + 1;len ++ ) {
        for (int i = 1;i + len - 1 <= n * 2;i ++ ) {
            int l = i, r = i + len - 1;

            for (int k = l + 1;k < r;k ++ ) {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + 1ll * a[l] * a[r] * a[k]);
            }
        }
    }
    ll ans = 0;
    for (int i = 1;i <= n;i ++ )
        ans = max(ans, f[i][i + n]);

    cout << ans << endl;



}