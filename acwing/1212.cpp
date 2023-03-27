/*
f[i][j][k][c]
表示 当前 走到 i j 格
手上 有 k 个 物品 且 最大 值 为 c 的 方案 数
f[i][j][k][c] += f[i - 1][j][k][c] + f[i][j - 1][k][c]
if (g[i][j] == c) {
    f[i][j][k][c] += (f[i - 1][j][k - 1][x < c] + f[i][j - 1][k - 1][x < c])
}

*/
#include <bits/stdc++.h>

using namespace std;

int f[55][55][15][15];
int g[55][55];
int n, m, k, mod = 1000000007;

int main() {
    cin >> n >> m >> k;
    f[1][1][0][0] = 1;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            cin >> g[i][j];
            g[i][j] ++ ;
        }
    }
    f[1][1][1][g[1][1]] = 1;

    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
             if (i == 1 && j == 1) continue;
            for (int z = 0;z <= k;z ++ ) {
                for (int v = 0;v <= 13;v ++ ) {
                    f[i][j][z][v] = (f[i][j][z][v] + f[i - 1][j][z][v] + f[i][j - 1][z][v]) % mod;
                    if (g[i][j] == v && z > 0) {
                        for (int u = 0;u < v;u ++ ) {
                            f[i][j][z][v] = (f[i][j][z][v] + f[i - 1][j][z - 1][u]) % mod;
                            f[i][j][z][v] = (f[i][j][z][v] + f[i][j - 1][z - 1][u]) % mod;
                            
                        }
                        
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0;i <= 13;i ++ ) ans = (ans + f[n][m][k][i]) % mod;
    cout << ans << endl;
}