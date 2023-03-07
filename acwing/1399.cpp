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

const int N = 2e5 + 10, M = (2e5 + 10) * 2;
template<typename T>
struct Flow {
	int s, t, n;
	int h[N], ne[M], e[M], idx, cur[N];
    T f[M] ,dis[N];
	
	void add(int a,int b, T c, T c2 = 0){
        e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++ ;
        e[idx] = a, ne[idx] = h[b], f[idx] = c2, h[b] = idx ++ ;
    }

	bool bfs() {
		for (int i = 1; i <= n; i++) dis[i] = 0, cur[i] = h[i];
		
		queue<int> q;
		q.push(s); dis[s] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = h[u]; ~i; i = ne[i]) {
			    int y = e[i];
				if (f[i] && !dis[y]) {
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
		for (int i = cur[u]; ~i; cur[u] = i = ne[i]){
		    int y = e[i];
			if (f[i] && dis[y] == dis[u] + 1) {
				T F = dfs(y, min(m, f[i]));
				f[i] -= F;
				f[i ^ 1] += F;
				m -= F;
				flow += F;
				if (!m) break;
			}
		}
		if (!flow) dis[u] = -1;
		return flow;
	}
	T dinic(){
		T flow=0;
		while (bfs()) flow += dfs(s, numeric_limits<T>::max());
		return flow;
	}
	void init(int s_, int t_, int vtot_) {
		s = s_;
		t = t_;
		n = vtot_;
		idx = 0;
		for (int i = 1; i <= n; i++) h[i] = -1;
	}
    void init() {
        for (int i = 0;i < idx;i += 2) {
            f[i] += f[i ^ 1];
            f[i ^ 1] = 0;
        }
    }
};

int n, m;
Flow<ll> f;

void solve() {
    cin >> n >> m;
    f.init(1, n, n);

    while (m -- ) {
        ll a, b, c; cin >> a >> b >> c ;
        c = c * 10000 + 1;
        f.add(a, b, c);
    }
    ll ans = f.dinic();
    cout << ans / 10000 << ' ' << ans % 10000 << endl;
    for (int i = 0;i < f.idx;i += 2 ) {
        f.init();
        ll t = f.f[i];
        f.f[i] = 0;
        ll d = f.dinic();
        if (d == ans - t) {
            cout << i / 2 + 1 << endl;
            ans = d; // 压缩 
        }   
        else f.f[i] = t;
    }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
