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

int n, m, k;
ll f[2010][2010], mod = 998244353;

void solve() {
    

    cin >> n >> m >> k;
    f[1][0] = m;
    for (int i = 2;i <= n;i ++ ) {
        for (int j = 0;j <= k;j ++ ) {
            f[i][j] = f[i - 1][j]; // 小朋友 与 前面 拿一样的
            if (j > 0)
                f[i][j] = (f[i][j] + f[i - 1][j - 1] * (m - 1)) % mod;
        }
    }
    cout << f[n][k] << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories