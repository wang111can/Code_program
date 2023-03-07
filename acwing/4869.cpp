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

const int N = 1e5 + 10;

int tr[N * 30][2];
int n, idx;

void insert(int x) {
    int p = 0;
    for (int i = 30;i >= 0;i -- ) {
        int t = x >> i & 1;
        if (!tr[p][t]) {
            tr[p][t]  = idx ++ ;
        }
        p = tr[p][t];
    }
}


int query(int p, int k) {
    int ans = 0;
    for (int i = k;i >= 0;i -- ) {
        if (tr[p][0] && tr[p][1]) {
            ans |= 1 << i;
            ans |= min(query(tr[p][0], i - 1), query(tr[p][1], i - 1)); 
        }
        else if (tr[p][0]) p = tr[p][0]; // 只有 0 和 只有 1 ans 该位 就 == 0
        else p = tr[p][1];
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int a; cin >> a;
        insert(a);
    }
    cout << query(0, 30) << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
