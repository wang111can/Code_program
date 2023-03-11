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

const int N = 110;

int n, m;
int g[N][N];
bool st[N][N];
PII match[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

bool find(int x, int y) {

    for (int i = 0;i < 4;i ++ ) {
        int a = dx[i] + x, b = dy[i] + y;
        if (a && b && a <= n && b <= n) {
            if (!g[a][b] && !st[a][b]) {
                st[a][b] = 1;
                if (match[a][b].x == 0 || find(match[a][b].x, match[a][b].y)) {
                    match[a][b] = {x, y};
                    return true;
                }
            }
        }
    }
    return false;

}

void solve() {
    cin >> n >> m;
    while (m -- ) {
        int a, b; cin >> a >> b;
        g[a][b] = 1;
    }
    
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= n;j ++ ) {
            if ((i + j & 1) && g[i][j] != 1) {          
                memset(st, 0, sizeof st);
                if (find(i, j)) ans ++ ;
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
//  --allow-unrelated-histories