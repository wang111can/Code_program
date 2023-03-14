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

int n;
pair<int, int> a[N];

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int t; cin >> t;
        a[i] = {t, i};
    }
    sort(a + 1, a + 1 + n); 
    int ans = 1, last = INT_MAX, trend = -1; // -1 下降 1 上升
    for (int i = 1;i <= n;i ++ ) {
        int j = i;
        while (j <= n && a[j].first == a[i].first) j ++ ;
        int v = a[i].first, minid = a[i].first, maxid = a[j].second;
        i = j;
        if (trend == -1) {
            if (last > maxid) {
                last = minid;
            }
            else {
                trend = 1, last = maxid;
            }
        }
        else {
            if (last < minid) {
                last = maxid;
            }
            else {
                ans ++ ;
                last = minid;
                trend = -1; 
            }
        }
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
//  --allow-unrelated-historiey