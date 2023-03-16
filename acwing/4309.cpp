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

int n, x, y;


void solve() {
    set<pair<int, int>> st;
    cin >> n >> x >> y;
    for (int i = 1;i <= n;i ++ ) {
        int a, b; cin >> a >> b;
        a -= x, b -= y;
        int d = __gcd(a, b);
        a /= d, b /= d;
        if (a < 0) {
            a = -a, b = -b;
        }
        st.insert({a, b});
    }
    cout << st.size() << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories