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

int tr[N][27], cnt[N], idx;
int n;
void insert(string str) {
    int p = 0;
    for (auto x : str) {
        int t = x - 'a';
        if (!tr[p][t]) tr[p][t] =  ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}

int query(string str) {
    int p = 0;
    for (auto x : str) {
        int t = x - 'a';
        if (!tr[p][t]){
            return 0;
        }
        p = tr[p][t];
    }
    return cnt[p];
}

void solve() {
    int n; cin >> n;
    while (n -- ) {
        string op; string str;
        cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
