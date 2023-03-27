#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1) 
mt19937_64 mrand(random_device{}());
typedef pair<int, int> PII;
typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ULL;
const double eps = 1e-8;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0), s(n + 1, 0);
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }
    
    while (m -- ) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}

int main()
{
	io;
    int T; T = 1 ;
    while (T -- )
    {
        solve();
    }
	return 0;
}
