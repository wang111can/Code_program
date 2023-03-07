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

const int N = 50;

int f[N][N][N];
// f[i][j][k] 第 i 个 第 j 个专辑 不超过 k 时间

void solve() {

    int n, m, t;
    cin >> n >> t >> m;
    for (int i = 1;i <= n;i ++ ) {
        int v; cin >> v;
        for (int j = 1;j <= m;j ++ ) {
            for (int k = 0;k <= t;k ++ ) {
                f[i][j][k] = f[i - 1][j][k]; 
                if (k >= v) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - v] + 1);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + 1);
                }
            }
        }
    }
    cout << f[n][m][t] << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
