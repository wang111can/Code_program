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

// f[i][j]
// 1 ~ i 
// 1 ~ j
// 路径点不重合的最大值
// 枚举第倒数第二个点
// f[i][j] = max(f[i][j], f[i][k] + 1); 1 ~ i 1 ~ k 的最大值 k ~ j
// ans 枚举倒数第二个点
// f[i][n] 1 ~ i i ~ n     1 ~ n 

map<string, int> mp;
int n, m;
int g[110][110];
int f[110][111];

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        string str; cin >> str;
        mp[str] = i;
    }
    
    while (m -- ) {
        string a, b; cin >> a >> b;
        int x = mp[a], y = mp[b];
        g[x][y] = g[y][x] = 1;
    }
    memset(f, -1, sizeof f);
    f[1][1] = 0;    
    
    for (int i = 1;i <= n;i ++ ) {
        for (int j = i + 1;j <= n;j ++ ) {
            for (int k = 1;k < j;k ++ ) {
                if (f[i][k] >= 0 && g[k][j]) {
                    f[i][j] = f[j][i] = max(f[i][j], f[i][k] + 1);
                    
                }
            }
        }
    }

    int ans = 1;
    for (int i = 1;i <= n;i ++ ) {
        if (f[i][n] > 0 && g[i][n]) {
            ans = max(ans, f[i][n] + 1);
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
