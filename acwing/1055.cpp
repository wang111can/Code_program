#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int f[N][2];
int n, w[N];

int main() {
    cin >> n;
    f[0][1] = -0x3f3f3f3f;
    for (int i = 1;i <= n;i ++ ) cin >> w[i];
    for (int i = 1;i <= n;i ++ ) {
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - w[i]);
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + w[i]);
    }
    cout << max(f[n][1], f[n][0]) << endl;
}