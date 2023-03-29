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

int n, d, k;
vector<int> a[100010];

void solve() {
    cin >> n >> d >> k;
    for (int i = 1;i <= n;i ++ ) {
        int t, id; cin >> t >> id;
        a[t].pb(id);
    }
    
    vector<bool> ans(100010, 0);
    vector<int> cnt(100010, 0);
    
    int l = 0;
    for (int i = 0;i <= 100010;i ++ ) {
        if (i - d + 1 > l) {
            for (auto x : a[l]) {
                cnt[x] -- ;
            }
            l ++ ;
        }
        for (auto x : a[i]) {
            cnt[x] ++ ;
            if (cnt[x] >= k) {
                ans[x] = 1;
            }
        }
    }
    for (int i = 0;i <= 100010;i ++ ) if (ans[i]) cout << i << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
