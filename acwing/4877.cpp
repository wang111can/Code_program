#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int f[15][1010];
int v[N], w[N], h[N], l[N];
int n, m;

int main() {
    cin >> m >> n >> v[1] >> w[1];
    n ++ ;
    for (int i = 2;i <= n;i ++ ) {
        cin >> l[i] >> h[i] >> v[i] >> w[i];
    }
    
    for (int i = 1;i <= n;i ++ ) {  
        for (int j = v[i];j <= m;j ++ ) {
            f[i][j] = f[i - 1][j];
            for (int k = 1;k * h[i] <= l[i] && k * v[i] <= j;k ++ ) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << f[n][m] << endl;

}