#include <bits/stdc++.h>

using namespace std;

/*

设 原 序列 可 表示 为
x + 
x + d1 + 
x + d1 + d2 + 
x + d1 + d2 + d3 + 

....
x + d1 + d2 + d3 + ... + dn - 1

nx + (n - 1)d1 + (n - 2)d2 + .. + dn-1 == S
x = (S - ((n - 1)d1 + (n - 2)d2 + ... + dn - 1)) / n
因为 为 整数 序列 
S % n == ((n - 1)d1 + (n - 2)d2 + ... + dn - 1)) % n
                n - 项
            可变换 为
            d1 + 2d2 + ... + (n - 1)dn - 1
f[i][j] 表示 前 i 项 和 的 余数 为 j 的 方案 数
f[i][j] = f[i - 1][(j - i * a) % n] + f[i - 1][(j + i * b) % n] 
f[0][0] = 1
*/

int f[1010][1010];
int n, a, b, s, mod = 100000007;


int main() {

    f[0][0] = 1;
    cin >> n >> s >> a >> b;
    for (int i = 1;i < n;i ++ ) {
        for (int j = 0;j < n;j ++ ) {
            f[i][j] = (f[i][j] + f[i - 1][(j - (n - i * a) % n + n) % n]) % mod;
            f[i][j] = (f[i][j] + f[i - 1][((j + (n - i) * b) % n + n) % n]) % mod;
        }
    }
    cout << f[n - 1][(s % n + n) % n] << endl;

}