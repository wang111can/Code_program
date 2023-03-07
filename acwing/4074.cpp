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

const int N = 410;

int g[N][N], s[N][N];

void solve() {
    int n, m; cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(s, 0x3f, sizeof s);
    while (m -- ) {
        int a, b; cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    for (int i = 1;i <= n;i ++ ) {
        g[i][i] = s[i][i] = 0;
        for (int j = i + 1;j <= n;j ++ ) {
            if (g[i][j] != 1) {
                s[i][j] = s[j][i] = 1;
            }
        }
    }
    for (int k = 1;k <= n;k ++ ) {
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 1;j <= n;j ++ ) {
                s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    if (s[1][n] == 0x3f3f3f3f || g[1][n] == 0x3f3f3f3f) {
        cout << -1;
    }
    else cout << max(s[1][n], g[1][n]);
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
