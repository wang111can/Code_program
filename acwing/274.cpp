/*
我们 可以 想到 
用f[i][x][y][z] 表示 完成 了 第 i 个 任务  此时 3 个 员工 分别 在 x y z 位置 的 值
f[i + 1][p[i + 1]][y][z] = min(f[i + 1][p[i + 1]][y][z], f[i][x][y][z] + w[x][p[i + 1]]) 
......

但是 空间 复杂度 为 1000 * 200^3 会 爆掉 空间 
我们 发现 在 第 i 个 任务 必定 会有一个 员工 在 p[i] 位置

我们 可以 使用 f[i][x][y]  p[i] 来表示 在 第 i 个 任务 员工 分别 在 x y p[i] 的  值
f[i + 1][x][y] = min(f[i + 1][x][y], f[i][x][y] + w[p[i]][p[i + 1]])
.....

*/


#include <bits/stdc++.h>

using namespace std;

int n, m;
int w[210][210];
int f[1010][210][210];
int p[1010];

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            cin >> w[i][j];
        }
    }

    for (int i = 1;i <= m;i ++ ) cin >> p[i];
    memset(f, 0x3f, sizeof f);
    p[0] = 3;
    f[0][1][2] = 0;

    for (int i = 0;i < m;i ++ ) {
        for (int x = 1;x <= n;x ++ ) {
            for (int y = 1;y <= n;y ++ ) {
                int z = p[i], v = f[i][x][y];
                if (x == y || x == z || y == z) continue;
                int u = p[i + 1];
                f[i + 1][x][y] = min(f[i + 1][x][y], v + w[z][u]);
                f[i + 1][z][y] = min(f[i + 1][z][y], v + w[x][u]);
                f[i + 1][x][z] = min(f[i + 1][x][z], v + w[y][u]);
            }
        }
    }
    
    int res = 0x3f3f3f3f;;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            if (p[m] == i || p[m] == j || i == j) continue;
            res = min(res, f[m][i][j]);
        }
    }
    cout << res << endl;


}