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

const int N = 1e5 + 10;

vector<PII> e[N];
bool st[N];
int dis[N];
int n, m;
int in[N];
int cnt[N];

void spfa() {
    memset(dis, 0x3f, sizeof dis);
    queue<int> q; 
    for (int i = 1;i <= n;i ++ ) {
        if (in[i]) {
            q.push(i);
            dis[i] = 0;
            st[i] = 1;
        }
    }
    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for (auto p : e[t]) {
            int x = p.x, y = p.y;
            if (dis[x] > dis[t] + y) {
                dis[x] = dis[t] + y;

                if (++ cnt[x] > n) {
                    cout << "Yes" << endl;
                    return;
                }
                if (!st[x]) {
                    
                    st[x] = true;
                    q.push(x);
                }
            }
        }
    }
    cout << "No" << endl;
}


void solve() {
    cin >> n >> m;
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back({b, c});
        in[a] = 1;
    }
    spfa();
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
