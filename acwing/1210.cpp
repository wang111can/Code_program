#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n; vector<int> a(n + 1, 0);
    
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i ++ ) {
        int minv = 0x3f3f3f3f, maxv = -0x3f3f3f3f;
        for (int j = i;j <= n;j ++ ) {
            minv = min(minv, a[j]);
            maxv = max(maxv, a[j]);
            if (maxv - minv == j - i) ans ++ ;
        }
    }
    cout << ans << endl;


}