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
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 200010, M = N * 2;

int h[N], e[N], ne[N], idx;
int n, m;

inline void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int st[N];

bool check(int u, int col) {
    st[u] = col;
    for (int i = h[u]; ~i;i = ne[i]) {
        int y = e[i];
        if (!st[y]) {
            if (!check(y, 3 - col)) {
                return false;
            }
        }
        else if (st[y] == col) return false;
    }

    return true;
}


void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m -- ) {
        int a, b; cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    for (int i = 1;i <= n;i ++ ) {
        if (!st[i]) {
            if (!check(i, 1)) {
                cout << "No" << endl;
                return ;
            }
        }
    }
    cout << "Yes" << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories