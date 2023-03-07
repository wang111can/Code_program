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

int n;
int d[30], ud[30];
int col[20];
vector<vector<int>> ans; 
vector<int> path;

void dfs(int u) {
    if (u > n) {
        ans.push_back(path);
        return;
    }
    
    for (int i = 1;i <= n;i ++ ) {
        if (!col[i] && !d[i + u] && !ud[n + i - u]) {
            col[i] = d[i + u] = ud[n + i - u] = 1;
            path.push_back(i);
            dfs(u + 1);
            path.pop_back();
            col[i] = d[i + u] = ud[n + i - u] = 0;
        }
    }
}

void solve() {
    cin >> n;
    dfs(1);
    sort(all(ans));
    for (int i = 0;i < 3;i ++ ) {
        for (auto x : ans[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << ans.size();
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
