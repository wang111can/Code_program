#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1)
#define all(x) x.begin(), x.end()
mt19937_64 mrand(random_device{}());

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

const int N = 7e6 + 10;

queue<ll> que, l, r;
int n, m, q, u, v, t;
ll offset, a[N];

ll get_(ll times) {
    ll x = -1, y = -1, z = -1;
    if (que.size()) x = que.front() + times * q;
    if (l.size()) y = l.front() + times * q;
    if (r.size()) z = r.front() + times * q;
    ll res = max({x, y, z});
    if (res == x) que.pop();
    else if (res == y) l.pop();
    else if (res == z) r.pop();

    return res;
}

void solve() {
    cin >> n >> m >> q >> u >> v >> t;
    double p =  u * 1.0 / v;

    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<ll>());
    for (int i = 1;i <= n;i ++ ) {
        que.push(a[i]);
    }
    
    for (int i = 1;i <= m;i ++ ){
        ll u = get_(i - 1);
        // cout << que.size() << "____" << endl ;
        if (i % t == 0) cout << u << ' '; 
        ll x = u * p, y = u - x;
        // cout << x << ' ' << y << endl;
        l.push(x - i * q);
        r.push(y - i * q); 
    }
    cout << endl;
    for (int i = 1;i <= m + n;i ++ ) {
        ll u = get_(m);
        if (i % t == 0) cout << u << ' ';
    }


// ssss


}

int main()
{
    io;
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
//  --allow-unrelated-histories 
