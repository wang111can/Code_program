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

int p[N], sz[N];
int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        p[i] = i;
    }
    fill(sz + 1, sz + 1 + n, 1);
    while (m -- ) {
        char op[3]; int a, b;
        cin >> op;
        if (op[0] == 'C'){
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b) {

                p[a] = b;   

                sz[b] += sz[a];
            }
        }
        else if (op[1] == '1'){
            cin >> a >> b;
            a = find(a), b = find(b);
            if (p[a] == p[b]) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else {
            cin >> a;
            cout << sz[find(a)] << endl;
        }
    }
}
int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
