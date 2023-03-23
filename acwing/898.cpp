#include <bits/stdc++.h> 

using namespace std;

int f[1010][1010];

int main() {
    int n; cin >> n;
    for (int i = 0;i <= n + 1;i ++ ) {
        for (int j = 0;j <= n + 1;j ++ ) {
            f[i][j] = INT_MIN;
        }
    }
    f[0][1] = f[0][0] = 0;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= i;j ++ ) {
            cin >> f[i][j];
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + f[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i = 1;i <= n;i ++ ) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;

}