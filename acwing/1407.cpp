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

const int N = 1010;

int f[N][N];
int g[N][N];
int n, t;

void solve() {
    cin >> n >> t;
    while (t -- ) {
        int a, b; cin >> a >> b;
        g[a][b] = 1; 
    }
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            if (!g[i][j]) {
                f[i][j] = 1;
                f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
                ans = max(ans, f[i][j]);
            }
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
