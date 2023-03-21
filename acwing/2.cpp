#include <bits/stdc++.h>

using namespace std;

int f[1010];

int main() {
    int n, v; cin >> n >> v;
    for (int i = 1;i <= n;i ++ ) {
        int a, b; cin >> a >> b;
        for (int j = v;j >= a;j -- ) {
            f[j] = max(f[j], f[j - a] + b);
        }
    }
    cout << f[v];
}