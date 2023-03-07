
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

int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
    
}


// 0 
// a b 同类
// 1 a 吃 根节点
// 2 根节点吃 a 
// a -- b = 0
// a b 之间的关系 为 (a -- x) - (b --- x) 

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) p[i] = i;
    
    int ans = 0;
    while (m -- ) {
        int t, x, y; cin >> t >> x >> y;
        if ((t == 2 && x == y) || x > n || y > n) ans ++ ;
        else {
            int relation = 0;
            if (t == 2) {
                relation = 1;
            }
            int a = find(x), b = find(y);
            if (a == b) {
                if (((d[x] - d[y]) % 3 + 3) % 3 != relation) {
                    ans ++ ;
                }
            }
            else {
                p[a] = b;
                d[a] = d[y] - d[x] + relation;
            }
        }
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
