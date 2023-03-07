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

const int N = 200;
int f[N][N], n;
int s[N], w[N];

void solve() {

    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }


    for (int len = 1;len <= n;len ++ ) {
        for (int i = 1;i + len - 1<= n;i ++ ) {
            int l = i, r = i + len - 1;
            f[l][r] = max(w[l] + s[r] - s[l] - f[l + 1][r], w[r] + s[r - 1] - s[l - 1] - f[l][r - 1]);
        }
    }
    cout << f[1][n] << ' ' << s[n] - f[1][n] << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
