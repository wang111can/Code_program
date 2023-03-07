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

const int N = 2e5 + 10;

int f[N], q[N], a[N];
int tt, hh, n, m;

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i ++ ) {
        if (hh <= tt && i - q[hh] > m) hh ++ ;
        f[i] = f[q[hh]] + a[i];
        while (hh <= tt && f[q[tt]] >= f[i]) tt -- ;
        q[++ tt] = i;
    }
    int res = 0x3f3f3f3f;
    for (int i = n;i > n - m ;i -- ) {
        res = min(res, f[i]);
    }
    cout << res;
}



int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
