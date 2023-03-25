#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int f[N], n, m;

int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1;i <= n;i ++ ) {
        int v; cin >> v;
        for (int j = m;j >= v;j -- ) {
            f[j] += f[j - v];
        }
    }
    cout << f[m] << endl;
}