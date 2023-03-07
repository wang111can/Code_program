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

int n, m;
int st[25];

void dfs(int u, int x) {
    if (u > n && x != m) {
        return;
    }
    if (x == m) {
        for (int i = 1;i <= n;i ++ ) {
            if (st[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    st[u] = 1;
    dfs(u + 1, x + 1);
    st[u] = 0;

    st[u] = 2;
    dfs(u + 1, x);
    st[u] = 0;
}

void solve() {

    cin >> n >> m;
    dfs(1, 0);

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
