#include <bits/stdc++.h>


using namespace std;

int f[1010][10010];

int main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    int d = 0;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        d = __gcd(a[i], d);
    }
    if (d != 1) {
        cout << "INF" << endl;
    }
    else {
        f[0][0] = 1;
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 0;j < 10010;j ++ ) {
                f[i][j] = f[i - 1][j];
                if (j >= a[i]) {
                    f[i][j] |= f[i - 1][j - a[i]];
                }
            }
        }
        int ans = 0;
        for (int i = 0;i < 10010;i ++ ) {
            if (!f[n][i]) ans ++ ;
        }
        cout << ans << endl;
    }


}