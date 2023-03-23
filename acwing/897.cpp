#include <bits/stdc++.h>

using namespace std;

int f[1010][1010];
char a[1010], b[1010];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    for (int j = 1;j <= m;j ++ ) cin >> b[j];
    
    int ans = 0;
   
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
}