#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n, m; cin >> w >> n >> m;
    n -- , m -- ;
    int x = n / w, y = m / w;
    int t1 = n % w, t2 = m % w;
    if (x % 2) t1 = w - 1 - t1;
    if (y % 2) t2 = w - 1 - t2;

    cout << abs(x - y) + abs(t1 - t2);

}