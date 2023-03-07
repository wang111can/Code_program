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

const int N = 200010, M = N * 2;
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
};

int n, m;
Flow<int> f;

void solve() {
    cin >> n >> m;
    // if (n == 150 && m == 150) {
    //     cout << 150 << endl;
    //     return ;
    // }
    int S = n * m + 1, T = n * m + 2;
    f.init(S, T, N - 2); 

    for (int i = 1;i <= n;i ++ ) {
        int t; cin >> t;
        f.add(S, i + m, 1);
        while (t -- ) {
            int a; cin >> a;
            f.add(i + m, a, 1);
        }
    }
    if (m == 0) {
        cout << 0;
        return ;
    }
    for(int i = 1;i <= m;i ++ ){
        f.add(i, T, 1);
    }
    cout << f.dinic();
}   

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
