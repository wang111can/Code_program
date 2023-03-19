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

const int N = 5e4 + 10;

vector<int> e[N];
int d[N], seq[N], n, m, cnt;

bitset<N> ans[N];

void top_sort() {

    queue<int> q;
    for (int i = 1;i <= n; i++ ) {
        if (!d[i]) {
            q.push(i);
        }
    }
    
    while (q.size()) {
        int t = q.front(); q.pop();
        seq[++ cnt] = t;
        for (auto x : e[t]) {
            if (-- d[x] == 0) {
                q.push(x);
            }
        }
    }

}

void solve() {
    cin >> n >> m;

    while (m -- ) {
        int a, b; cin >> a >> b; e[a].push_back(b);
        d[b] ++ ;
    }

    top_sort();

    for (int i = n; i;i -- ) {

        int t = seq[i];
        // cout << t << "AAA" << endl;
        ans[t][t] = 1;
        for (auto x : e[t]) {
            ans[t] |= ans[x];
        }
    }
    for (int i = 1;i <= n;i ++ ) {
        // cout << ans[i] << endl;
        cout << ans[i].count() << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories