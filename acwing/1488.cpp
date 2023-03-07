
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

vector<PII> e[N];
int n, m, k, q; 
int store[N];
int dis[N];
bool st[N];

void spfa(int u) {
    
    memset(dis, 0x3f, sizeof dis);
    queue<int> q; q.push(u);
    dis[u] = 0;

    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for (auto  pa: e[t]) {
            if (dis[pa.x] > dis[t] + pa.y) {
                dis[pa.x] = dis[t] + pa.y;
                if (!st[pa.x]) {
                    q.push(pa.x);
                    st[pa.x] = true;
                }
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    cin >> k;
    for (int i = 1;i <= k;i ++ ){
        int a; cin >> a;
        e[n + 1].push_back({a, 0});
    }
    spfa(n + 1);
    cin >> q;
    while (q -- ) {
        int a; cin >> a;
        cout << dis[a] << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}

