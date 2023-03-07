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



ll n, x;
ll s[100010];

void solve() {
    cin >> n >> x;
    n -- ;
    x *= 2;
    for (int i = 1;i <= n;i ++ ) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    function<bool(ll)> check = [&](ll mid) {
        
        for (int i = 0;i + mid <= n;i ++ ) {
            if (s[i + mid] - s[i] < x) {
                return false;
            }
        }

        return true;
    };
    ll l = 1, r = 100010;
    while (l < r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
