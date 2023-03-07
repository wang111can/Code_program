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

int a[1010], b[1010];
int T;
struct Node{
    int x, y;
    bool operator<(const Node &c) const{
        return x > c.x;
    }
};

void op(int n, int f[]) {
    priority_queue<Node> q;

    for (int i = 1;i <= n;i ++ ) {
        int a; cin >> a;
        q.push({a, a});
    }

    for (int i = 1;i <= T;i ++ ) {
        auto t = q.top(); q.pop();
        f[i] = t.x;
        t.x += t.y;
        q.push(t);
    }

}

void solve() {
   int m1, m2; cin >> T >> m1 >> m2;
    op(m1, a);
    op(m2, b);
    int ans = 0;
    for (int i = 1, j = T;i <= T;i ++ , j -- ) {
        ans = max(a[i] + b[j], ans);
    }
    cout << a[T] << ' ' << ans << endl;

}

int main() {
	io;
     solve();
	return 0;
}
