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

const int N = 100010;

ll h[N], idx, l[N], r[N], w[N];
ll dis[N], n, k, a[N];
bool st[N];





void solve() {
    cin >> n >> k;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
    }
    memset(h, -1, sizeof h);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for (int i = 1;i < n;i ++ ) {
        dis[i] = a[i + 1] - a[i];
        l[i] = i - 1, r[i] = i + 1;
        q.push({dis[i], i});
    }
    dis[0] = dis[n] = inf;

    /*
        每个 点 
        a b c d 
        若 当前 最小 的  线段 是 b c 那么 我们 就不能 选择 ab 与 cd
        若 不选 bc 选 ab 那么 我们必须 选中 cd 因为 只选择 ab 那么 cd 是 空余的 因为 bc < ab 那么 我们 可以 不选择 ab 去选择 bc 
        所以 当选择 ab 时 我们 必须 选择 cd  

    */


    function<void(ll)> op = [&](ll x) {
        st[x] = true;
        r[l[x]] = r[x];
        l[r[x]] = l[x];
    };
    ll res = 0;
    while (k -- ) {
        while (st[q.top().y]) q.pop();
        auto t = q.top(); q.pop();
        // cout << t.x << ' ' << t.y << endl;
        res += t.x;
        ll left = l[t.y], right = r[t.y];   
        dis[t.y] = dis[left] + dis[right] - dis[t.y];
        op(left); op(right);
        q.push({dis[t.y], t.y});
    }
    cout << res << endl;
    

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories