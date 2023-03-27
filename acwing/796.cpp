#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1) 
mt19937_64 mrand(random_device{}());
typedef pair<int, int> PII;
typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ULL;
const double eps = 1e-8;


void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    auto s = a;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
        }
    }
    while (q -- ) {
        int x, y, xx, yy; cin >> x >> y >> xx >> yy;
        cout << s[xx][yy] - s[x - 1][yy] - s[xx][y - 1] + s[x - 1][y - 1] << endl;
    }
}

int main()
{
	io;
    int T; T = 1 ;
    while (T -- )
    {
        solve();
    }
	return 0;
}
