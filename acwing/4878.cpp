#include <bits/stdc++.h>


using namespace std;
using ll = long long;
const int N = 2e5 + 10;

ll n, k, a, b, q;
ll w[N], ta[N], tb[N];

inline ll lowbit(ll x) {
    return x & -x;
}

void add(ll tr[], ll x, ll y) {
    for (;x <= n;x += lowbit(x)) tr[x] += y;
}

ll ask(ll tr[], ll x) {
    ll res = 0;
    for (; x;x -= lowbit(x)) res += tr[x];
    return res;
}


int main() {
    cin >> n >> k >> a >> b >> q;

    while (q -- ) {
        ll op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (w[x] < a) {
                if (w[x] + y >= a) {
                    add(ta, x, a - w[x]);
                }
                else {
                    add(ta, x, y);
                }
            }
            if (w[x] < b) {
                if (w[x] + y >= b) {
                    add(tb, x, b - w[x]);
                }
                else {
                    add(tb, x, y);
                }
            }
            w[x] += y;
        }
        else {
            cin >> x;
            cout << ask(tb, x - 1) + ask(ta, n) - ask(ta, x + k - 1) << endl;
        }
    }


}