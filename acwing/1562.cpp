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

const int N = 1010, M = 2020;

vector<int> e[N];
int dis[N], n, L, m;
bool st[N];

int bfs(int u) {
    fill(dis + 1, dis + 1 + n, 0);
    fill(st + 1, st + 1 + n, 0);
    queue<int> q; q.push(u);
    int ans = 0; st[u] = 1;

    while (q.size()) {
        int t = q.front(); q.pop();
        if (dis[t] == L) {
            continue;
        }

        for (auto x : e[t]) {
            if (dis[x] == 0 && !st[x]) {
                ans ++ ;
                dis[x] = dis[t] + 1;
                st[x] = true;
                q.push(x);
            }
        }
    }
    return ans ;
}

void solve() {
    cin >> n >> L;
    for (int i = 1;i <= n;i ++ )  {
        int s; cin >> s;
        while (s -- ) {
            int a; cin >> a;
            e[a].push_back(i);
        }
    }

    cin >> m;
    while (m -- ) {
        int a; cin >> a;
        cout << bfs(a) << endl;
    }

    


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
