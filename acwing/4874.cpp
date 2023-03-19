#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

ll primes[N], st[N], cnt;
int n;

int main() {
    for (int i = 2;i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0;primes[j] * i < N;j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }

    scanf("%d", &n);
    
    while (n -- ) {
        ll x; scanf("%lld", &x);
        ll t = sqrt(double(x));
        if (x > 1 && t * t == x && !st[t]) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    
    return 0;
}