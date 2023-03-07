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

int g[10][10];
int n, m, k;
set<string> st; 
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int x, int y, string str, int ct) {
    if (ct > k) {
        st.insert(str);
        return ;
    }
    for (int i = 0;i < 4;i ++ ) {
        int a =  x + dx[i], b = y + dy[i];
        if (a && b && a <= n && b <= m) {
            dfs(a, b, str + char(g[a][b] + '0'), ct + 1);
        }
    }
}


void solve() {
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            cin >> g[i][j];
        }
    }
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            dfs(i, j, to_string(g[i][j]), 1);
        }
    }
    cout << st.size() << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
