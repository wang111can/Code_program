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

int d1[20], d2[20], col[20];
int g[20][20];
int n;

void dfs(int u, int ct) {
    if (u > n) {
        if (ct == n) {
            for (int i = 1;i <= n;i ++ ) {
                for (int j = 1;j <= n;j ++ ) {
                    if (g[i][j] == 1) {
                        cout << 'Q';
                    }
                    else cout << '.';
                }
                cout << endl;
            }
        }
        cout << endl;
        return ;
    }

    // d1 = -d2
    // d1 = u + i
    // d2 = -u + i
    for (int i = 1;i <= n;i ++ ) {
        if (!col[i] && !d1[i + u] && !d2[n - u + i]) {
            col[i] = d1[i + u] = d2[n - u + i] = 1;
            g[u][i] = 1;
            dfs(u + 1, ct + 1);
            g[u][i] = 0;
            col[i] = d1[i + u] = d2[n - u + i] = 0;
        }
    }

}



void solve() {
    cin >> n;
    dfs(1, 0);


}


int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
