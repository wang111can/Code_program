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

int a[N];
pair<int, int> op[N];
int top, n, m;


void solve() {
    cin >> n >> m;

    while (m -- ) {
        int x, y; cin >> x >> y;
        if (x == 0) {
            
            while (top && op[top].x == 0) y = max(y, op[top -- ].y);
            while (top >= 2 && op[top - 1].y <= y) top -= 2 ;
            op[++ top] = {0, y};
        }
        else if (top) {
            
            while (top && op[top].x == 1) y = min(y, op[top -- ].y);
            while (top >= 2 && op[top - 1].y >= y) top -= 2 ;
            op[top ++ ] = {1, y};
        }
    }
    int l = 1, r = n, k = n;
    for (int i = 1;i <= top;i ++ ) {
        if (op[i].x == 0) {
            while (l < r && op[i].y <= r) a[r -- ] = k -- ;
        }
        else {
            while (l < r && op[i].y >= l) a[l ++ ] = k -- ;
        }
    }
    
    if (top % 2) {
        while (l < r) a[l ++ ] = k -- ;
    }
    else while (l < r) a[r -- ] = k -- ;

    for (int i = 1;i <= n;i ++ ) cout << a[i] << ' ';
    
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
