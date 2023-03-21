/*
f[i][j] = max(f[i - 1][j], f[i - 1][j - v], f[i - 1][j - 2v]....)
f[i][j - v] = max(f[i - 1][j - 2v] ... )
f[i][j] = max(f[i - 1][j], f[i][j - v])
*/

#include <bits/stdc++.h>

using namespace std;

int f[1010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        int a, b; cin >> a >> b;
        for (int j = m;j >= a;j -- ) {
            f[j] = max(f[j], f[j - a] + b);
        }
    }
    cout << f[m] << endl;
}