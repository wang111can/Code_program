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
typedef long long LL ;
typedef unsigned long long ULL;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const LL INF = 1e18;

LL n;

LL cal(LL a, LL b) {

    LL res = 1;
    for (int i = a, j = 1;j <= b; i --, j ++ ){
        res =  res * i / j;
        if (res > n) {
            return res;
        }
    }
    return res;

}


bool check(LL u) {

    LL l = 2 * u, r = max(n, l);

    while (l < r) {
        LL mid = l + r >> 1;
        if (cal(mid, u) >= n) r = mid;
        else l = mid + 1;
    }
    if (cal(r, u) != n) {
        return false;
    } 

    LL ans = r * (r + 1) / 2 + u + 1;
    cout << ans << endl;
    return true;

}

void solve() {
    cin >> n;

    for (LL i = 16;;i -- ) {
        if (check(i))
            break;
    }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
