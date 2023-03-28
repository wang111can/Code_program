#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int a[100010], b[100010], c[100010];
int n;

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    for (int i = 1;i <= n;i ++ ) cin >> b[i];
    for (int i = 1;i <= n;i ++ ) cin >> c[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);

    long long ans = 0;

    for (int i = 1;i <= n;i ++ ) {
        int l = lower_bound(a + 1, a + 1 + n, b[i]) - a - 1;
        int r = upper_bound(c + 1, c + 1 + n, b[i]) - c;
        if (l >= 1 && r <= n)
            ans += 1ll * l * (n - r + 1);
    }
    cout << ans << endl;

}