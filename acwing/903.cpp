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

typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ULL;
const double eps = 1e-8;

typedef pair<ll, ll> PII;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;


const int N = 1010;


vector<pair<ll, ll>> e[N];
ll m, n, le[N], w[N];
ll dis[N];
bool st[N];

ll dijkstra(int l, int r) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for (int i = 0;i <= n;i ++ ) st[i] = 0, dis[i] = INF;
    q.push({0, 0});
    dis[0] = 0;

    while (q.size()) {
        auto t = q.top(); q.pop();
        if (st[t.y]) continue;
        st[t.y] = 1;
        for (auto p : e[t.y]) {
            int x = p.x, y = p.y;
            if (le[x] >= l && le[x] <= r) {
                if (dis[x] > dis[t.y] + y) {
                    dis[x] = dis[t.y] + y;
                    q.push({dis[x], x});
                }
            }
         }
    }
    
    return dis[1];

}

void solve() {
    cin >> m >> n;
    for (int i = 1;i <= n;i ++ ) {
        int s;
        cin >> w[i] >> le[i] >> s;
        e[0].pb({i, w[i]});
        while (s -- ) {
            int a, b; cin >> a >> b;
            e[a].push_back({i, b});
        }
    }

    ll res = INF;
    for (int i = le[1] - m;i <= le[1];i ++ )  {
        res = min(res, dijkstra(i, i + m));
    }
    cout << res << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
