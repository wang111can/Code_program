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

const int N = 1e6 + 10;

int t[N][30], cnt[N], idx;
int n, m;

void insert(string & str) {
    int p = 0;
    
    for (auto x : str) {
        int q = x - 'a'  + 1;
        if (t[p][q] == 0) t[p][q] = ++ idx;
        p = t[p][q];
    }
    cnt[p] ++ ;
}

int query(string &str) {
    int ans = 0, p = 0;
    for (auto x : str) {
        int q = x - 'a'  + 1;
        if (!t[p][q]) return ans;
        p = t[p][q];
        ans += cnt[p];
    }
    // ans += cnt[p];
    return ans;


}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n; i ++ ) {
        string str; cin >> str;
        insert(str);
    }

    for (int i = 1;i <= m;i ++ ) {
        string ask; cin >> ask;
        cout << query(ask) << endl;
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