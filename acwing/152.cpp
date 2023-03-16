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


const int N = 1010;

int g[N][N], l[N], r[N], n, m;
int q[N];

int op(int a[]) {
    int hh = 0, tt = 0;
    
    a[0] = a[m + 1] = -1;
    q[0] = 0;
    for (int i = 1;i <= m;i ++ ) {
        while (a[q[tt]] >= a[i]) tt -- ;
        l[i] = q[tt];
        q[++ tt] = i;
    }
    hh = 0, tt = 0;
    q[0] = m + 1;
    for (int i = m;i >= 1;i --  ) {
        while (a[q[tt]] >= a[i]) tt -- ;
        r[i] = q[tt];
        q[++ tt] = i;
    }

    int res = 0;
    for (int i = 1;i <= m;i ++ ) res = max(res, a[i] * (r[i] - l[i] - 1));
    return res;

}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            char c; cin >> c;
            if (c == 'F') {
                g[i][j] = g[i - 1][j] + 1; // 该行往上行有 多少 个 f 
            } 
        }
    }

    int ans = 0;
    for (int i = 1;i <= n;i ++ ) ans = max(ans, op(g[i]));
    cout << ans * 3 << endl; 
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories