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


void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + 1, 0);
    vector<array<int, 3>> e;
    int ans = 0;
    while (m -- ) {
        int a, b, c; cin >> a >> b >> c;
        e.push_back({a, b, c});
        e.push_back({b, a, c});
        ans += c;
    }
    for (int i = 0;i <= n;i ++ ) p[i] = i;
    sort(all(e), [&](array<int, 3> a, array<int, 3> b) {
        return a[2] < b[2];
    });
    function<int(int)> find = [&](int x) {
        if (p[x] != x) return p[x] = find(p[x]);
        return p[x];
    };
    for (auto arr : e) {
        int a = arr[0], b = arr[1], c = arr[2];
        a = find(a), b = find(b);
        if (a != b) {
            ans -= c;
            p[a] = b;
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
