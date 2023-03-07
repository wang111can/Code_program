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

    // f[i][j]  以 i,j 结尾的1 最大正方形边长
    // f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1
    const int N = 300;

    int f[N][N], n;

    void solve() {

        cin >> n;
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 1;j <= n;j ++ ) {
                char c; cin >> c;
                if (c == '1') {
                    f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}) + 1;
                }
            }
        }

        vector<int> ans(n + 1, 0);
        for (int i = 1;i <= n;i ++ ) {
            for (int j = 1;j <= n;j ++ ) {
                for (int k = 2;k <= f[i][j];k ++ ) {
                    ans[k] ++ ;
                }
            }
        }
        for (int i = 1;i <= n;i ++ ) {
            if (ans[i]) {
                cout << i << ' ' << ans[i] << endl;
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
