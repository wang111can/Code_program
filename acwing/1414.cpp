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

int tr[2100000][2], id[2100000], idx, a[N];
int n;


void insert(int x, int k)
{
    int p = 0;
    for (int i = 20; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (!tr[p][u]) tr[p][u] = ++ idx;
        p = tr[p][u];
    }
    id[p] = k;
}

int query(int x)
{
    int p = 0;
    for (int i = 20; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (tr[p][!u]) p = tr[p][!u];
        else p = tr[p][u];
    }
    return id[p];
}


void solve() {

    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int x; cin >> x;
        a[i] = a[i - 1] ^ x;;
    }
    insert(a[0], 0);
    int l = 0, r = 0;
    int ans = -1;   
    for (int i = 1;i <= n;i ++ ) {
        int k = query(a[i]);
        int t = a[i] ^ a[k];
        // cout << k << ' ' << t << ' ' << i << endl;
        if (t > ans) {
            ans = t;
            l = k + 1, r = i;
        }
        insert(a[i], i);

    }
    cout << ans << ' ' << l << ' ' << r << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
