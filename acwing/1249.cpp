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

const int N = 2e5 + 10;

int p[N];
int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        p[i] = i;
    }
    for (int i = 1;i <= m;i ++ ) {
        int a, b; cin >> a >> b;
        p[find(a)] = find(b);
    }

    cin >> m;
    for (int i = 1;i <= m;i ++ )  {
        int a, b;
        cin >> a  >> b;
        if (p[find(a)] == p[find(b)]) {
            puts("Yes");
        }
        else puts("No");
    }
} 

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
