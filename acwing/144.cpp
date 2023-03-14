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

// 任意 2 点 的 异或 值 == 从 2 点 到 根 的 异或值

vector<PII> e[100010];
int t[3000010][2], idx;
int path[100010];

void dfs(int u, int fa, int sum) {
    path[u] = sum;
    for (auto p : e[u]) {
        if (p.x != fa) {
            dfs(p.x, u, sum ^ p.y);
        }
    }
}

void insert(ll x) {
    int p = 0;
    for (int i = 31;i >= 0;i -- ) {
        int q = x >> i & 1;
        if (t[p][q] == 0) t[p][q] = ++ idx;
        p = t[p][q];
    }
}

int query(ll x) {
    int p = 0, res = 0;
    for (int i = 31;i >= 0;i -- ) {
        int q = x >> i & 1;
        if (t[p][!q]) {
            res |= 1 << i;
            p = t[p][!q];
        }
        else p = t[p][q];
    }
    return res;
}


void solve() {

    int n; cin >> n;
    for (int i = 1;i < n;i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        a ++ , b ++ ;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    dfs(1, -1, 0);

    for (int i = 1;i <= n;i ++ ) insert(path[i]);

    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        ans = max(ans, query(path[i]));
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
//  --allow-unrelated-histories