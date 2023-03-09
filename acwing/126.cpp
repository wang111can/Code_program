#include <bits/stdc++.h>

using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            int x; cin >> x;
            a[i][j] = a[i - 1][j] + x;
        }
    }
    // 分成 列 

    int res = INT_MIN;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = i;j <= n;j ++ ) {
            int maxv = 0;
            for (int k = 1;k <= n;k ++ ) {
                maxv = max(maxv, 0) + a[j][k] - a[i - 1][k];
                res = max(res, maxv);
            }
        }
    }
    cout << res;

}