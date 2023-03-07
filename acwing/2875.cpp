// a b c
/* (1) a * b + c * (a + b)
    a * b + c * a + c * b
 
 (2) a * (c + b ) + c * b
    a * c + a * b + c * b
    
(1) == (2)
直接求
 
*/

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

void solve() {
    int n; cin >> n;
    vector<ll> s(n + 1, 0);
    for (int i = 1;i <= n;i ++ ) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    ll ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        ans += (s[i] - s[i - 1]) * (s[n] - s[i]);
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
