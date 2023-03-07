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

vector<int> e[100010];

int in[100010];
int q[100010];
    int n, m;

void topsort() {
    int hh = 0, tt = -1;
    
    for (int i = 1;i <= n;i ++ ) {
        if (in[i] == 0) {
            q[++ tt] = i;
        }
    }
    while (hh <= tt) {
        int t = q[hh ++ ];

        for (auto x : e[t]) {
            if (-- in[x] == 0 ){
                q[++ tt] = x;
            }
        }
    }
    if (tt == n - 1) {
        for (int i = 0;i <= tt;i ++ ) {
            cout << q[i] << ' ';
        }
    }
    else cout << -1 << endl;

}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= m;i ++ ) {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        in[b] ++ ;
    }
    topsort();

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
