/*
性质 b 序列 的 每个 元素 一定 出现 在 a 序列 中

设 a b 序列 长度 为 k
当 k == 1, a = b 满足 性质
达能 k > 1 
设 目前 已经 安排好 长度 为 j 的 序列 
当前 位置 为 j + 1
若 b[j] <= a[j + 1] b[j + 1] = a[j + 1] 
若 b[j] > a[j + 1] 已知 b[j + 1] >= b[j] 所以 当 b[j + 1] == b[j] 时 可是 b[j + 1] - a[j + 1] 的 绝对值 最小
因为 b[j] == b[j - 1] or b[j] == a[j], b[j - 1] == b[j - 2] or b[j - 1] == a[j - 1] 以此类推 我们 可以 得到 b[j] 一定 属于 a 序列

f[i][j] 表示 当前 枚举 到 ai 选 aj 的 最小 S
f[i][j] = min(f[i][j], {f[i - 1][j], f[i - 1][j - 1], f[i - 1][j - 2] ...... }) + |a[i] - a[j]|
                        该段 可以 使用 一个 值 来 维护
*/  


#include <bits/stdc++.h>

using namespace std;

int a[2010], b[2010];
int n, f[2010][2010];

int work() {
    for (int i = 1;i <= n;i ++ ) b[i] = a[i];
    sort(b + 1, b + 1 + n); 

    for (int i = 1;i <= n;i ++ ) {
        int minv = INT_MAX;
        for (int j = 1;j <= n;j ++ ) {
            minv = min(minv, f[i - 1][j]);
            f[i][j] = minv + abs(a[i] - b[j]);
        }
    }


    int res = INT_MAX;
    for (int i = 1;i <= n;i ++ ) res = min(res, f[n][i]);

    return res ;
}

int main(){
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    int res = work();
    reverse(a + 1, a + 1 + n);
    res = min(res, work());

    cout << res << endl;

    return 0;
}