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

vector<int> e[N];
vector<int> ie[N];
int n, m, w[N];

void spfa(vector<int> &tm, int u, bool flag) {
    queue<int> q; q.push(u);
    vector<bool> st(n + 1, 0);
    tm[u] = w[u];
    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        vector<int> h;
        if (!flag) {
            h = e[t];
        }
        else h = ie[t];
        for (auto x:h) {
            if (!flag && tm[x] > min(w[x], tm[t]) || flag && tm[x] < max(w[x], tm[t])) {
                if (!flag) tm[x] = min(w[x], tm[t]);
                else tm[x] = max(w[x], tm[t]);
                if (!st[x]) {
                    q.push(x);
                    st[x] = true;
                }
            }
        }
    }

}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        cin >> w[i];
    }

    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        
        e[a].push_back(b);
        ie[b].push_back(a);
        if (c == 2){
            e[b].push_back(a);
            ie[a].push_back(b);
        }
    }   
    vector<int> minv(n + 1, inf), maxv(n + 1, 0); 
    spfa(minv, 1, 0);
    spfa(maxv, n, 1);
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        ans = max(ans, maxv[i] - minv[i]);
        // cout << maxv[i] << ' ' << minv[i] << endl;
        
    }
    cout << ans << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
