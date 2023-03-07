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

// f[i] a[1 ~ i] ^ a[j] 的最大 j 下标
const int N = 2e6 + 10;

ll f[N], pos[N];
ll n, m, x;

void solve() {

    cin >> n >> m >> x;
    for (int i = 1;i <= n;i ++ ) {
        ll t; cin >> t;
        f[i] = max(f[i - 1], pos[t ^ x]);
        pos[t] = i;
    }
    
    while (m -- ) {
        int l, r; cin >> l >> r;
        if (f[r] < l) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
