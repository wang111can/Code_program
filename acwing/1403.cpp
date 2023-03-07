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

int f[N][N];
// f[i][j] 从 i 开始 与 从 j 开始 最大匹配 长度
int ans = 0, a[N], n;

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
    }

    for (int i = n; i;i -- ) {
        for (int j = n;j > i;j -- ) {
            if (a[j] - a[i] != a[j + 1] - a[i + 1]) {
                f[i][j] = 1;
            }
            else f[i][j] = max(f[i][j], f[i + 1][j + 1] + 1);
            ans = max(ans, min(f[i][j], j - i));
        }
    }
    if (ans < 5) {
        cout << 0;
    }
    else cout << ans;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
