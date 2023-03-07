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

const int N = 10010;

vector<PII> e[N];
int w[N], n, m, k, s;   
bool have[N], st[N];
int dis[N];


void solve() {
    cin >> n >> m >> k >> s;
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    for (int i = 1;i <= n;i ++ ) cin >> w[i];
   
    for (int i = 1;i <= m;i ++ ) {
        int a; cin >> a;
        have[a] = true;
        dis[a] = 0;
        st[a] = true;
        q.push(a);
    }

    while (k -- ) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    auto spfa = [&]{
        
        while (q.size()) {
            int t = q.front(); q.pop();
            st[t] = false;

            for (auto p : e[t]) {
                int x = p.x, y = p.y;
                if (have[t] && have[x]) {
                    have[y] = true;
                    if (dis[y] > max(dis[x], dis[t]) + max(w[x], w[t])){
                        dis[y] = max(dis[x], dis[t]) + max(w[x], w[t]);
                        if (!st[y]) {
                            q.push(y);
                            st[y] = true; 
                        }
                    }
                 }
            }
        }
    };
    spfa();
    
    cout << dis[s] << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
