#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1) 
#define all(x) x.begin(), x.end()
mt19937_64 mrand(random_device{}());

typedef pair<int, int> PII;
typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

ll mod = 200907;
ll a, b, c, k;

ll cal(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res ;
}

void solve() {
    cin >> a >> b >> c >> k;
    if (a + c == 2 * b) {
        cout << (a + (b - a) * (k - 1) % mod) % mod << endl;
    }
    else cout << a * cal(b / a, k - 1) % mod << endl;
}


int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories