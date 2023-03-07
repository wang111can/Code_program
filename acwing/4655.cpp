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

const int N = 1e5 + 10;

int n, m; 
int tr[N];


int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c) {
    for (int i = x;i <= n; i += lowbit(i)) {
        tr[i] += c;
    }
}

int ask(int x) {
    int res = 0;
    for (int i = x;i;i -= lowbit(i)) {
        res += tr[i];
    }
    // cout << res << endl;
    return res;
    
}
ll a[N];
ll b[N];

void solve() {
    cin >> n; 
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    cin >> m;

    while (m -- ) {
        int l, r; cin >> l >> r;
        add(l, 1);
        add(r + 1, -1);
    }
    // for (int i = 1;i <= n;i ++ ) {
    //     cout << tr[i] << endl;
    // }  
    ll pre = 0;
    for (int i = 1;i <= n;i ++ ) {
        b[i] = ask(i);
       // cout << ask(i) << endl;
        pre += b[i] * a[i];
    }
    ll now = 0;
    sort(b + 1, b + 1 + n);
    
    sort(a + 1, a + 1 + n);

    for (int i = 1;i <= n;i ++ )  {
        now += b[i] * a[i];
    }
    cout << now - pre << endl;





}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
