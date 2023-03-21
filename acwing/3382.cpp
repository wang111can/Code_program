#include <bits/stdc++.h>

using namespace std;

int f[1000010];

int main() {
    int n, mod = 1e9;
    cin >> n;
    f[0] = 1;
    for (int i = 1;i <= n;i *= 2) {
        for (int j = i;j <= n;j ++ ) {
            f[j] = (f[j - i] + f[j]) % mod;
        }
    }
    cout << f[n] << endl;

}