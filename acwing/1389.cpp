
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

string a, b;
int pos[1010];
void dfs(int il, int ir, int l, int r) {
    if (il > ir) return;
    if (l > r) return;

    int p = pos[b[l]];
    dfs(il, p - 1, l + 1, l + 1 + p - 1 - il);
    dfs(p + 1, ir, l + 1 + p - il, r);

    cout << b[l];

}


void solve() {
    cin >> a >> b;
    int n = a.size();
    for (int i = 0;i < n;i ++ ) {
        pos[a[i]] = i;
    } 
    dfs(0, n - 1, 0, n - 1);
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
