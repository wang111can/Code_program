#include <bits/stdc++.h>


using namespace std;

int f[50010], g[50010];
int n;

int main() {

    int T; cin >> T;
    while (T -- ) {
        cin >> n;
        vector<int> a(n + 1, 0);
        fill(f, f + n + 1, -0x3f3f3f3f);
        fill(g, g + 1 + n + 2, -0x3f3f3f3f);
        int maxv = -0x3f3f3f3f;
        
        for (int i = 1;i <= n;i ++ ) {
            cin >> a[i];
            maxv = max(maxv, 0) + a[i];
            f[i] = max({f[i - 1], maxv});

        }
        maxv = -0x3f3f3f3f;
        for (int i = n; i;i -- ) {
            
            maxv = max(maxv, 0) + a[i];
            g[i] = max(g[i + 1], maxv);
        }
        int ans = -0x3f3f3f3f;
        for (int i = 1;i <= n;i ++ ) {
            ans = max(ans, f[i] + g[i + 1]);
        }
        cout << ans << endl;
    }

    

}