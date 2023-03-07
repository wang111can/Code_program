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

const int N = 1e7 + 10;

int tr[N][2], cnt[N], n, m, idx;
int s[N];

void insert(int x, int v) {
    int p = 0;
    for (int i = 30;i >= 0;i -- ) {
        int  t = x >> i & 1;
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
        cnt[p] += v;    
    }
}

int query(int x) {
    int res = 0, p = 0;
    for (int i = 30;i >= 0;i -- ) {
        int t = x >> i & 1;
        if (cnt[tr[p][!t]]) {
            p = tr[p][!t];
            res = res * 2 + 1;
        }
        else res = res * 2, p = tr[p][t];
    }
    return res ;
}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) cin >> s[i], s[i] ^= s[i - 1];
    insert(0, 1);

    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        if (i > m) {
            insert(s[i - m - 1], -1);
        }
        ans = max(query(s[i]), ans);
    
        insert(s[i], 1);
        
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
