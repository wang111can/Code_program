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


const int N = 200;

vector<int> e[N];
int n, in[N], out[N];
bool st[N][N];
bool instk[N];
int stk[N], times, scc, id[N], dfn[N], low[N], top;

void tarjan(int u) {
    dfn[u] = low[u] = ++ times;
    stk[++ top] = u, instk[u] = true;
    for (auto x : e[u]) {
        if (!dfn[x]) {
            tarjan(x);
            low[u] = min(low[u], low[x]);
        }
        else if (instk[x]) {
            low[u] = min(low[u], dfn[x]);
        }
    }
    if (dfn[u] == low[u]) {
        int y;
        ++ scc;
        do {
            y = stk[top -- ];
            id[y] = scc;
            instk[y] = false;
        } while (y != u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int a;
        while (cin >> a, a) {
            e[i].push_back(a);
        }
    }
    for (int i = 1;i <= n;i ++ ) {
        if (!dfn[i]) tarjan(i);
    }


    for (int i = 1;i <= n;i ++ ) {
        for (auto x : e[i]) {
            if (id[i] != id[x] ) {
                out[id[i]] ++ ;
                in[id[x]] ++ ;  
            }
        }
    }
    int c1 = 0, c2 = 0;
    for (int i = 1;i <= scc;i ++ ) {
        if (!out[i]) c1 ++ ;
        if (!in[i]) c2 ++ ;
    }
    cout << c2 << '\n' << (scc == 1?0:max(c1, c2)) << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
