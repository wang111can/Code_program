#include <bits/stdc++.h>


using namespace std;
using ll = long long;

const int N = 3010;

int f[N][N], n;
ll a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    for (int i = 1;i <= n;i ++ ) cin >> b[i];
    
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        int max_len = 1;
        for (int j = 1;j <= n;j ++ ) {
            f[i][j] = (f[i - 1][j]);
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], max_len);
            }   
            if (a[i] > b[j]) {
                max_len = max(max_len, f[i][j] + 1); // 之前 的 最长 公共 上升 子序列 的 长度  + 1 
            }
            ans = max(ans, f[i][j]);
            // for (int k = 1;k < j;k ++ ) {
            //     f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            //     if (b[k] < b[j] && b[j] == a[i]) {
            //         f[i][j] = f[i - 1][j - 1] + 1;
            //     }
            //     ans = max(ans, f[i][j]);
            // } 
        }
    }
    cout << ans << endl;


    return 0;
}