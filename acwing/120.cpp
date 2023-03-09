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

const int N = 2e5 + 10;

int MX, n;
struct Node {
    ll a, d, t;
}p[N];


ll sum(ll mid) {
    ll res = 0; 
    for (int i = 1;i <= n;i ++ ) {
        if (p[i].a <= mid) {
            res += (min(p[i].t, mid) - p[i].a) / p[i].d + 1;
        }
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int a, d, t; cin >> a >> t >> d;
        p[i] = {a, d, t};
        MX = max(t, MX);
        
    }
    ll l = 0, r = MX;
    while (l < r) {
        int mid = l + r >> 1;
        if (sum(mid) % 2) r = mid;
        else l = mid + 1;
    }
    if (sum(r) % 2 == 0) {
        cout << "There's no weakness." << endl;
    }
    else cout << r << ' '  << sum(r) - sum(r - 1) << endl;
}

int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
