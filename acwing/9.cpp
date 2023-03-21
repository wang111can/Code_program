#include <bits/stdc++.h>

using namespace std;

int s[110], v[110][110], w[110][110];
int f[110];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        cin >> s[i];
        for (int j = 1;j <= s[i];j ++ ){
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for (int i = 1;i <= n;i ++ ) {
        for (int j = m;j >= 0;j -- ) { // j 与 k 的 循环 不能 换位置
            for (int k = 1;k <= s[i];k ++ ) {
                int a = v[i][k], b = w[i][k];
                if (j >= a) {
                    f[j] = max(f[j], f[j - a] + b);
                }
                
            }
        }
    }
    cout << f[m] << endl;
    
}