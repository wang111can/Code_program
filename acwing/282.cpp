#include <bits/stdc++.h>

using namespace std;


int f[1010][1010];
int n, a[1010];

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i], a[i] += a[i - 1];
    
    for (int len = 2;len <= n;len ++ ) {
        for (int i = 1;i + len - 1 <= n;i ++ ) {
            int l = i, r = i + len - 1;
            f[l][r] = 0x3f3f3f3f;
            for (int k = l;k < r;k ++ ) {  
                f[l][r] = min({f[l][r], f[l][k] + f[k + 1][r] + a[r] - a[l - 1]});
            }
        }
    }
    cout << f[1][n];
}