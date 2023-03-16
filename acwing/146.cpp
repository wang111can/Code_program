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



void solve() {
    int n, m; cin >> m >> n;
    vector<int> a, b, c;
    function<void()> op = [&]() {
        c.clear();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> q;
        for (int i = 0;i < n;i ++ ) q.push({a[0] + b[i], 0}); 

        // a0 + b1, a0 + b2 ...
        // a1 + b1 ..
        // .....
        for (int i = 0;i < n;i ++ ) {
            auto t = q.top(); q.pop();
            c.push_back(t.x);
            q.push({t.x + a[t.y + 1] - a[t.y], t.y + 1});
        }
        a = c;
    };

    for (int i = 0;i < n;i ++ ) {
        int t; cin >> t;
        a.push_back(t);
    }
    sort(all(a));
    for (int i = 1;i < m;i ++ ) {
        b.clear();
        for (int j = 0;j < n;j ++ ) {
            int t; cin >> t;
            b.push_back(t);
        }
        sort(all(b));
        op();
    }
    for (int i = 0;i < n;i ++ ) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories