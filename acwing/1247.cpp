#include <bits/stdc++.h>

using namespace std;

const int N = 10;
// 表示 第 i 个 骰子 最上面的 面 是 多少
// a b 不能 相邻 那么就是 a 的 对立 面 不能 在 上面 那个 面
int n, m, mod = 1e9 + 7;

void work(int f[], int a[], int b[][N]) {
    int tmp[N] = {0};
    for (int i = 0;i < 6;i ++ ) {
        for (int j = 0;j < 6;j ++ ) {
            tmp[i] = (tmp[i] + 1ll * a[j] * b[j][i] % mod) % mod;
        }
    }
    for (int i = 0;i < 6;i ++ ) {
        f[i] = tmp[i];
    }
}

void work(int f[][N], int a[][N], int c[][N]) {
    int tmp[N][N] = {0};
    for (int i = 0;i < 6;i ++ ) {
        for (int j = 0;j < 6;j ++ ) {
            for (int k = 0;k < 6;k ++ ) {
                tmp[i][j] = (tmp[i][j] + 1ll * a[i][k] * c[k][j] % mod) % mod;
            }
        }
    }
    
    for (int i = 0;i < 6;i ++ ) {
        for (int j = 0;j < 6;j ++ ) {
            f[i][j] = tmp[i][j];
        }
    }
}


int main() {
    
    
    int f[N] = {4, 4, 4, 4, 4, 4}; // 初始 情况
    // f[i][j] = f[i - 1][k1] * k + f[i - 1][k2] * 4 +.....
    // 可以 发现 * k 是 一个 特定 的 矩阵
    int a[N][N] = {0};
    
    for (int i = 0;i < 6;i ++ ) {
        for (int j = 0;j < 6;j ++ ) {
            a[i][j] = 4; 
        }
    }
    cin >> n >> m;

    auto get_ = [&](int x) {
        if (x >= 3) return x - 3;
        else return x + 3;
    };
    
    while (m -- ) {
        int x, y; cin >> x >> y; x -- ,y -- ;
        a[x][get_(y)] = 0;
        a[y][get_(x)] = 0;
    }
    
    
    
    for (int i = n - 1; i;i >>= 1) {
        if (i & 1) work(f, f, a);
        work(a, a, a);
    }
    
    int ans = 0;
    for (int i = 0;i < 6;i ++ ) ans = (ans + f[i]) % mod;
    cout << ans << endl;
        
}