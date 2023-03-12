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

const int N = 1010;

vector<int> p;
bool st[N];


void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    for (auto x : p) {
        if (x > n) break;
        for (int i = 1;i < p.size();i ++) {
            if (p[i] + p[i - 1] + 1 == x) ans ++ ;
        } 
    }
    if (ans >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
	io; int T; cin >> T;
    for (int i = 2;i < N;i ++ ) {
        if (!st[i]) p.push_back(i);
        for (int j = 0;p[j] * i < N;j ++ ) {
            st[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories