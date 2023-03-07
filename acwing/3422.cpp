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

vector<int> e[N];
int n, son[N];

int dfs(int u) {
    int res = son[u];
    for (auto x : e[u]){
        res = max(res, son[x]  + dfs(x));
    }
    return res ;
}

void solve() {

    cin >> n;
    for (int i = 2;i <= n;i ++ ) {
        int y; cin >> y;
        son[y] ++ ;
        e[y].push_back(i);
    }
    cout << dfs(1) << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
