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

const int N = 300010;

int a[N];

void solve() {
    int l = 1;
    int n, m; cin >> n >> m;
    int ans = -0x3f3f3f3f, sum = 0;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        if (i - l - 1 > m) {
            sum -= a[l];
            l ++ ;
        }
        sum += a[i];
        ans = max(sum, ans);
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
