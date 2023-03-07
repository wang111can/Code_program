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
    ull n, x; cin >> n >> x;
    if (x == 1) {
        cout << -1 << endl;
        return;
    }
    else {
        queue<ull> q; q.push(x);
        ull end = pow(10, n - 1);

        unordered_map<ull, int> dis;
        dis[x] = 0;
        while (q.size()) {
            auto t = q.front(); q.pop();

            for (ull digit = t;digit;digit /= 10) {
                if (digit % 10 == 0 || digit % 10 == 1) continue;
                    if (dis[digit % 10 * t]) continue;
                    dis[digit % 10 * t] = true;
                    q.push(digit % 10 * t);
                    dis[digit % 10 * t]  =dis[t] + 1;
                    if (digit % 10 * t >= end) {
                        cout << dis[digit % 10 * t] << endl;
                        return ;
                    }
            }
        
        }
        cout << - 1 << endl;
    }
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
