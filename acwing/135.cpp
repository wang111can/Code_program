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
// s[i] - 前面最小的
int q[N];
void solve() {

    int n, k; cin >> n >> k;
    int ans = -0x3f3f3f3f, sum = 0, hh = 0, tt = 0;
    

    vector<int> s(n + 1, 0);
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (hh <= tt && i - q[hh] > k) hh ++ ;
        ans = max(ans, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i]) tt -- ;

        q[++ tt] = i;
        
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
