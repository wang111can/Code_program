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

int minv[N], g[N][N];
int n, m, a[N], color[N];

bool dfs(int u, int col) {
    color[u] = col;
    for (int i = 1;i <= n;i ++ ) {

        if (g[u][i]) {
            if (color[i] == col) return false;
            if (color[i] == -1 && !dfs(i, !col)) return false;
        }

    }
    return true;
}



void solve() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    memset(color, -1, sizeof color);
    minv[n + 1] = n + 1;

    for (int i = n;i >= 1;i -- ) minv[i] = min(minv[i + 1], a[i]);
    // 两个 数 不能 进入 同一个 栈 当 i < j < k   wk < wi < wj 
    for (int i = 1;i <= n;i ++ ) {
        for (int j = i + 1;j <= n;j ++ ) {
            if (a[i] < a[j] && minv[j + 1] < a[i]) {
                g[i][j] = g[j][i] = true;
            }
        }
    }
    // for (int i = 1;i <= n;i ++ ) {
    //     for (int j = 1;j <= n;j ++ ) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1;i <= n;i ++ ) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                cout << 0 << endl;
                return;
            }
        }
    }

    stack<int> q1, q2;
    int num = 1;
    int j = 1;
    for (int i = 1;i <= 2 * n;i ++ ) {
        if (j <= n && color[j] == 0 && (q1.size() == 0 || (q1.size() && q1.top() > a[j]))) {
            cout << "a ";q1.push(a[j]); j ++ ; 
        }
        else if (q1.size() && q1.top() == num) {
            cout << "b " ; q1.pop(); num ++ ;
        }
        else if (j <= n && color[j] == 1 && (q2.size() == 0 || (q2.size() && q2.top() > a[j]))) {
            cout << "c ";  q2.push(a[j]);j ++ ;
        }
        else if (q2.size() && q2.top() == num) {
            cout << "d "; num ++ ; q2.pop() ;
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
//  --allow-unrelated-histories