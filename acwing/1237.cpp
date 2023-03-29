#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll get_(ll x, ll y, ll a, ll b) {
    return abs(x - a) + abs(y - b);
}

int main() {
    ll x, y, k; cin >> x >> y; k = max(abs(x), abs(y));
    ll dis = 4 * k * k;
    ll xt = k, yt = k;
    if (x < xt && y > -yt) {
        cout << dis - get_(x, y, xt, yt);
    }
    else cout << dis + get_(x, y, xt, yt);

}