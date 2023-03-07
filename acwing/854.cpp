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

ll g[N][N];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1;i <= n;i ++ ){
        for (int j = 1;j <= n;j ++ ) {
            g[i][j] = INF;
        }
    }
    while (m -- ) {
        ll a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    for (int i = 1;i <= n;i ++ ) g[i][i] = 0;
    for (int k = 1;k <= n;k ++ ) {
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 1;j <= n;j ++ ) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    
    while (k -- ) {
        int a, b; cin >> a >> b;
        if (g[a][b] > INF / 2) {
            cout << "impossible" << endl;
        }
        else cout << g[a][b] << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
