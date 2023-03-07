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



int n;
int g[10][10], c[10][10];

vector<pair<int, int>> step;

void op(int x, int row) {
    for (int i = 0;i < 4;i ++ ) {
        if (x >> i & 1) {
            for (int j = 1;j <= 4;j ++ ) {
                c[row][j] = !c[row][j];
            }
            for (int j = 1;j <= 4;j ++ ) {
                c[j][i + 1] = !c[j][i + 1];
            }
            c[row][i + 1] = !c[row][i + 1];
            step.push_back({row, i + 1});
        }
    }

}

void solve() {
    for (int i = 1;i <= 4;i ++ ) {
        for (int j = 1;j <= 4;j ++ ) {
            char ch; cin >> ch;
            if (ch == '+') {
                g[i][j] = 1;
            }
            else g[i][j] = 0;
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0;i < (1 << 4);i ++ ) {
        for (int j = 0;j < (1 << 4);j ++ ) {
            for (int z = 0;z < (1 << 4);z ++ ) {
                for (int k = 0;k < (1 << 4);k ++ ) {
                    memcpy(c, g, sizeof g);
                    step.clear();
                    op(i, 1), op(j, 2), op(z, 3), op(k, 4);
                    bool success = true;
                    for (int i = 1;i <= 4;i ++ ) {
                        for (int j = 1;j <= 4;j ++ ) {
                            if (c[i][j]) {
                                success = false;
                            }
                        }
                    }
                    if (success) {
                        if (ans.empty() || ans.size() > step.size()) {
                            ans = step;
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p:ans) {
        cout << p.x << ' ' << p.y << endl;
    }


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
