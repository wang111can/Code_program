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

const int N = 2e6 + 10;
template<class T> 
struct Flow {
    int n, s, t;
    T f[N], e[N], ne[N], idx, dis[N], h[N], cur[N], w[N];

    void init(int _s, int _t, int _n) {
        s = _s, t = _t, n = _n;
        idx = 0;
        for (int i = 0;i <= n;i ++ ) h[i] = -1;

    }
    void add(int a, int b, int c) {
        e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++ ;
        e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++ ;
    }

    bool bfs() {
        for (int i = 0;i <= n;i ++ ) cur[i] = h[i], dis[i] = 0;
        queue<int> q; q.push(s); dis[s] = 1;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = h[u]; ~i;i = ne[i]) {
                int y = e[i];
                if (f[i] && dis[y] == 0) {
                    dis[y] = dis[u] + 1;
                    if (y == t) return true;
                    q.push(y);
                }
            }
        }
        return false;
    }

    T dfs(int u, T m) {
        if (u == t) return m;
        T flow = 0;
        for (int i = h[u]; ~i; cur[i] = i = ne[i]){
            int y = e[i];
            if (f[i] && dis[y] == dis[u] + 1) {
                T F = dfs(y, min(m, f[i]));
                f[i] -= F;
                f[i ^ 1] += F;
                flow += F;
                m -= F;
                if (!m) break;
            }
        }

        if (!flow) dis[u] = -1;
        return flow;

    }

    void change(int mid) {

        for (int i = 0; i < idx;i += 2) {
            if (w[i] > mid) {
                f[i] = 0;
            }
            else f[i]  = 1;
        }
    }

    T dinic() {
        T flow = 0;
        while (bfs()) flow += dfs(s, INT_MAX);
        return flow;
    }
};

int n, m, s, t;
Flow<ll> f; 

void check(int mid) {
    f.change(mid);
    if (f.dinic() == n) {

    } 
}

vector<array<int, 3>> edge;

bool work(int mid) {
    f.init(s, t, t);
    int cnt = 0;
    for (auto arr : edge) {
        if (arr[2] < mid) {
            cnt ++ ;
            f.add(s, arr[0], 1);
            f.add(arr[0], arr[1], 1);
            f.add(arr[1], t, 1);

        }
    }
    cout << mid << ' ' << cnt << ' ' << f.dinic() << endl;
    if (f.dinic() == cnt) return true;
    return false;
}

void solve() {
    cin >> n >> m;
    s = n + m  + 1, t = n + m + 2;
    f.init(s, t, t);
    ll maxv = 0;
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;    
        edge.push_back({a, b, c});
        maxv = max(maxv, (ll)c);
    }

    int l = 0, r = maxv;
    while (l < r) {
        int mid = l + r >> 1;
        if (work(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;

}
int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories