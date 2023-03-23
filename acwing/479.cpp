/*
中序 遍历 可以 以 任意点 为 根

*/


#include <bits/stdc++.h>

using namespace  std;


int f[110][110];
int a[110], dot[110][110];
int n;


int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    
    for (int len = 1;len <= n;len ++ ) {
        for (int i = 1;i + len - 1 <= n;i ++ ) {
            int l = i, r = i + len - 1;
            for (int k = l;k <= r;k ++ ) {
                int leftw = k == l?1:f[l][k - 1];
                int rightw = k == r?1:f[k + 1][r];
                int weight =  leftw * rightw + a[k];
                if (l == r) weight = a[k];
                if (f[l][r] < weight) {
                    f[l][r] = weight;
                    dot[l][r] = k; // 这个 区间 的 根
                } 
            }
        }
    }

    cout << f[1][n] << endl;
    function<void(int, int)> dfs = [&](int l, int r){
        if (l > r) return;
        cout << dot[l][r] << ' ';
        dfs(l, dot[l][r] - 1);
        dfs(dot[l][r] + 1, r);

    };    
    dfs(1, n);
}
