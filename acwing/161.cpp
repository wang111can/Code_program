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

const int N = 2e5 + 10;

int tr[N][20];
int idx, ed[N], cnt[N];
int n;


bool insert(string &str) {
    int p = 0;
    for (int i = 0;i < str.size();i ++ ) {
        int  x = str[i] - '0';
        if (!tr[p][x]) tr[p][x] = ++ idx;
        p = tr[p][x];
        if (ed[p]) return false;
        cnt[p] ++ ;
    }
    ed[p] = 1;
    if (cnt[p] > 1) return false;
    return true;
    

}

void solve() {
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    memset(tr, 0, sizeof tr);
    memset(ed, 0, sizeof ed);
    idx = 0;
    string s[N];
    for (int i = 1;i <= n;i ++ ) cin >> s[i];
    for (int i = 1;i <= n; i ++ ) {
        if (!insert(s[i])) {
            cout << "NO" << endl;

            return ;
        }
    }
    cout << "YES" << endl;
}

int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories