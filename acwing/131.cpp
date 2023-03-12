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

const int N = 1e5 + 10;

int l[N], r[N], a[N], n;
int q[N];

void solve() {
    while (cin >> n, n) {
        // cin >> n;
        memset(q, 0, sizeof q);
        
        for (int i = 1;i <= n;i ++ ) cin >> a[i];
        int tt = 0;
        a[0] = a[n + 1] = -1;
        for (int i = 1;i <= n; i++ ) {
            while (a[q[tt]] >= a[i]) tt -- ;
            l[i] = i - q[tt];
            q[++ tt] = i;
        }
        
        tt = 0, q[0] = n + 1;
        for (int i = n;i >= 1;i -- ) {
            while (a[q[tt]] >= a[i]) tt -- ;
            r[i] = q[tt] - i;
            q[++ tt] = i;
        }
        
        ll ans = 0;
        for (int i = 1;i <= n;i ++ ) {
            ans = max(ans, 1ll * a[i] * (l[i] + r[i] - 1));
        }
        cout << ans << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories