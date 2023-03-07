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

const int N = 5010;

int f[75536], g[N];
int a[N], n;

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i], f[i] = 1;

    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j < i;j ++ ) {
            if (a[j] > a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        for (int j = 1;j < i;j ++ ) {
            if (f[i] == f[j] && a[i] == a[j]) 
                f[j] = -1;
        }
        for (int j = 1;j < i;j ++ ) {
            if (a[j] > a[i] && f[j] + 1 == f[i]) 
                g[i] += g[j]; // 以a[j]结尾 的不同方案数量
        }
        if (f[i] == 1) g[i] = 1; 
    }
    cout << *max_element(f + 1, f + 1 + n) << ' ';
    int cnt = 0;
    for (int i = 1;i <= n;i ++ ) {
        if (f[i] == *max_element(f + 1, f + 1 + n)) {
            cnt += g[i];
        }
    }
    cout << cnt << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
