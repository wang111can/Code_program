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

const int N = 510;


int g[N][N], cost[N];
int n;

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            cin >> g[i][j];
        }
    }

    for (int i = 1;i <= n;i ++ ) cin >> cost[i];
    

    vector<int> used;
    vector<ll> ans;
    for (int i = n; i;i -- ) {
        int u = cost[i]; // 只经过 倒数 n - i + 1 个 点 的 最小 方案
        used.push_back(u);
        for (int j = 1;j <= n;j ++ ){
            for (int z = 1;z <= n;z ++ ) {
                g[j][z] = min(g[j][z], g[j][u] + g[u][z]);
            }
        }
        
        ll sum = 0;
        for (auto x : used) {
            for (auto y : used) {
                sum  += g[x][y];
            }
        }  
        ans.push_back(sum);
    }
    reverse(all(ans));
    for (auto x : ans) {
        cout << x << ' ' ;
    }


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories