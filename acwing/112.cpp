
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

struct Node {
    double x, y;
    bool operator<(const Node& z) {
        return y < z.y;
    }

}p[N];

int n;
double d;

double get_(double y) {
    return sqrt(pow(d, 2) - pow(y, 2));
}

void solve() {
    cin >> n >> d;
    for (int i = 1;i <= n;i ++ ) {
        double x, y; cin >> x >> y;
        if (y > d) {
            cout << -1 << endl;
            return ;
        }
        p[i] = {x - get_(y), x + get_(y)};
    }
    sort(p + 1, p + 1 + n);

    int ans = 1;
    double dot = p[1].y;
    for (int i = 2;i <= n;i ++ ) {
        if (p[i].x > dot) {
            ans ++ ;
            dot = p[i].y;
        }
    }
    cout << ans << endl;


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
