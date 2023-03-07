
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


// 队列 内 存储的 是 比当前元素大 且 能取到的 最大值
// 取到 q[k] 时 q[k + 1] ~ i 最大的元素 就是 a[q[k + 1]]
//  
const int N = 1e5 + 10;

ll q[N], f[N], a[N];
multiset<ll> st;

void move(ll x) {
    auto it = st.find(x);
    st.erase(it);
}

void solve() {
    ll n; ll m; cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        if (a[i] > m) {
            cout << -1;
            return;
        }
    }

    ll tt = 0, hh = 0, sum = 0;
    for (int i = 1, j = 0;i <= n;i ++ ) {
        sum += a[i];
        while (sum > m) sum -= a[ ++ j];
        while (hh <= tt && q[hh] < j){
            if (hh < tt) { // 保证 st 里 至少有一个值
                move(f[q[hh]] + a[q[hh + 1]]);
            }
             hh ++ ;
        }
        while (hh <= tt && a[q[tt]] < a[i]) {
            if (hh < tt) {
                move(f[q[tt - 1]] + a[q[tt]]);
            }
            tt -- ;
        }
        q[++ tt] = i;
        if (hh < tt) {
            st.insert(f[q[tt - 1]] + a[q[tt]]);
        }
        f[i] = f[j] + a[q[hh]];

        // 找 f[q[k]] + a[q[k + 1]] 的最小值 那么 我们可以再维护
        // for (int k = hh;k <= tt;k ++ ) f[i] = min(f[i], f[q[k]] + a[q[k + 1]]);
        if(!st.empty()) f[i] = min(f[i], *st.begin());
    }
    cout << f[n] << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}