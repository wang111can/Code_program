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
typedef unsigned long long ULL;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 1e5 * 31 + 10;

int tr[N][2], idx;
int n;
ll a[N];

void solve() {
    cin >> n;
    function<void(ll)> insert = [&](ll x) {
        int p = 0;
        for (int i = 31;i >= 0;i -- ) {
            int t = x >> i & 1;
            if (!tr[p][t]) tr[p][t] = ++ idx;
            p = tr[p][t];
        }
    };
    function<ll(ll)> query = [&](ll x) {
        ll res = 0ll;
        int p = 0;
        for (int i = 31;i >= 0;i -- ) {
            int t = x >> i & 1;
            if (tr[p][!t]) {
                p = tr[p][!t];
                res = res << 1 | 1;
            }
            else res <<= 1, p = tr[p][t];
        }

        return res;

    };
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        insert(a[i]);
    }   
    
    ll ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
