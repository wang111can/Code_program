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

const int N = 1e6 + 10;

int q[N], a[N];
int n;

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    int hh = 0, tt = -1;
    for (int i = 1;i <= n;i ++ ) {
        if (hh <= tt && i - k + 1 > q[hh] ) hh ++ ;
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        q[++ tt] = i;
        if (i >= k)
        cout << a[q[hh]] << ' ';
    }
    cout << endl;
    memset(q, 0, sizeof q);
    hh = 0, tt = -1;
    
    for (int i = 1;i <= n;i ++ ) {
        if (hh <= tt && i - k + 1 > q[hh] ) hh ++ ;
        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[++ tt] = i;
        if (i >= k)
        cout << a[q[hh]] << ' ';
    }
    

    
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
