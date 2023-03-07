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

int p[N], d[N], sz[N];
int n;

int find(int x)  {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

// 30000
void solve() {

    fill(sz + 1, sz + 1 + 30010, 1);
    for (int i = 1;i <= 30010;i ++ ) p[i] = i;    

    int m; cin >> m;
    while (m -- ) {
        char op; int a, b;
        cin >> op >> a >> b;
        int x = find(a), y = find(b);
        if (op == 'M') {

            if (x != y) {
                p[x] = y;
                d[x] = sz[y];
                sz[y] += sz[x];
                
            }
        }
        else {
            if (x == y) {
                cout << max(abs(d[a] - d[b]) - 1, 0) << endl;
            }
            else cout << -1 << endl;
        }
    }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
