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

const int N = 2010;

int p[N], n, m, sz[N];
PII q[N];

int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

int work(int u) {

    for (int i = 1;i <= n;i ++ ) p[i] = i, sz[i] = 1;
    int surplus = 1;

    for (int i = 1;i <= u;i ++ ) {
        int a = find(q[i].x), b = find(q[i].y);
        if (a == b) {
            surplus ++ ;
        }
        else sz[b] += sz[a], p[a] = b;
    }
    int max_v = 0;
    vector<int> cnt;
    for (int i = 1;i <= n;i ++ ) {
        if (p[i] == i) {
            cnt.pb(sz[i]);
        }
    }
    sort(all(cnt)); reverse(all(cnt));
    for (int i = 0;i < cnt.size() && surplus;i ++ , surplus -- ) max_v += cnt[i];
    return  max_v - 1 + surplus ;

}

void solve() {
    cin >> n >> m;
    
    for (int i = 1;i <= m;i ++ ) {  
        cin >> q[i].x >> q[i].y;
        cout << work(i) << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
