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

ll n, w, c[20], g[20];
int ans = inf;
bool st[20];

void dfs(int u, int ct) {
    if (u > ans) {
        return;
    }
    if (ct > n) {
        ans = min(ans, u);
        return ;
    }
    for (int i = 1;i <= u;i ++ ) {
        if (g[i] + c[ct] <= w) {
            g[i] += c[ct];
            dfs(u, ct + 1);
            g[i] -= c[ct]; 
        }
    }
    g[u + 1] += c[ct];
    dfs(u + 1, ct + 1);
    g[u + 1] -= c[ct];


}

void solve() {
    cin >> n >> w;
    for (int i = 1;i <= n;i ++ ) {
        cin >> c[i];
    }
    sort(c + 1, c + 1 + n, greater<ll>());

    dfs(1, 1);
    cout << ans << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
