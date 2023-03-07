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

const int N = 200, M = 20010;


// dp 求方案
int f[N][M];
int n, m, v[N];


vector<int> plan, path;

void dfs(int u, int s) {
    if (!u) {
        if (plan.empty() || plan > path) plan = path;
        return;
    }
    if (f[u][s] == f[u - 1][s]) dfs(u - 1, s); // 说明这个点用不到
    
    path.push_back(v[u]);
    
    for (int j = s - v[u];j >= 0;j -= v[u]) {
        // 状态可转移
        if (f[u][s] == f[u - 1][j] + 1) {
            dfs(u - 1, j);
        }
    }
    
    path.pop_back();
}


void solve() {

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    cin >> m >> n;
    for (int i = 1;i <= n;i ++ ) { 
        cin >> v[i];
    }
    sort(v + 1, v + 1 + n, greater<int>());
    int ans = inf;
    for (int i = 1;i <= n;i ++ ) {
        
        for (int k = 0;k < v[i];k ++ ) {
            int min_v = inf;
            for (int j = k;j <= m;j += v[i]) {
                f[i][j] = min(min_v + 1, f[i - 1][j]);// 能用前面 的凑到的
                
                min_v = min(min_v, f[i - 1][j]);
                
            }
        }
        ans = min(f[i][m], ans);
    }
    dfs(n, m);
    cout << ans << ' ';
    for (auto x : plan) cout << x << ' ';
    


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
