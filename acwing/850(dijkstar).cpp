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

const int N = 2e5 + 10;

vector<pair<int, int>> e[N];
int n, m;
int dis[N];

int dijkstra(int u) {
    for (int i = 1;i <= n;i ++ ) {
        dis[i] = 1e9 + 10;
    }
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({1, 0});

    while (q.size()) {
        pair<int, int> p = q.top(); q.pop();

        for (auto x:e[p.x]) {
            if (dis[x.x] > dis[p.x] + x.y) {
                dis[x.x] = dis[p.x] + x.y;
                q.push({x.x, dis[x.x]});
            }
        }
    }
    return dis[n];


}

void solve() {
    cin >> n >> m;
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    int t = dijkstra(1);
    if (t == 1e9 + 10) {
        cout << -1;
    }
    else cout << t;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
