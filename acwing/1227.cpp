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

PII a[100010];
int n, k;

void solve() {
    cin >> n >> k;
    int mxv = 0;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i].x >> a[i].y; 
        mxv = max({a[i].x, a[i].y, mxv});
    }
    
    function<bool(int)> check = [&](int x){
        int cnt = 0;
        for (int i = 1;i <= n;i ++ ) {
            int l = a[i].x / x, r = a[i].y / x;
            cnt += l * r; 
        }

        return cnt >= k;
    };
    
    int l = 1, r = mxv;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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
