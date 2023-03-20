#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;


ll w[N], L[1 << 26], R[N], a[N], n, m;
ll k, cnt;
ll ans;

bool dfs(int u, ll s) {

    if (u > k) {
        L[++ cnt] = s;
        return true;
    }
    dfs(u + 1, s);
    if (s + a[u] <= m) dfs(u + 1, s + a[u]);

}

bool dfs(int u, ll s, bool flag) {
    if (u > n) {
        int l = 0, r = cnt;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (s + L[mid] <= m) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, L[l] + s);
        return true;
    }
    dfs(u + 1, s, flag);
    if (s + a[u] <= m) dfs(u + 1, s + a[u], flag);
}

int main() {
    cin >> m >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];

    sort(a + 1, a + 1 + n, greater<ll>());
    k = n / 2;
    dfs(1, 0);
    sort(L + 1, L + 1 + cnt);
    dfs(k + 1, 0, true);
    cout << ans << endl;
    return 0;
}