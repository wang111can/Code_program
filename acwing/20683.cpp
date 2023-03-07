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


int ct[15][100010];
ll a[100010], n, k;

void solve() {

    cin >> n >> k;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        ll t = a[i] % k;
        for (int j = 0;j < 13;j ++) {
            ct[j][t] ++ ;
            t = t * 10 % k;
        }
    }
    // (A_j * 10^leni + A_i) % k == 0
    // A_j * 10^leni % k + A_i % k == 0
    // a + b == 0
    // a = b = 0
    // a + b = k

    ll ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        int len = to_string(a[i]).size();
        int t = a[i] % k;
        ans += ct[len][(k - t) % k];
        int r = a[i] % k;
        while (len -- ) {
            r = r * 10 % k;
        }
        if (r == (k - t) % k) {
            ans -- ;
        }

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
