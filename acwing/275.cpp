/*
可以得出 f[i][x1][y1][x2][y2] 为 当前 走 i 步 分别 到达 x1 y1 x2 y2 的 值
时间复杂度 空间复杂度 为 n^5
x1 + y1 = x2 + y2 = i
y1 = i - x1 y2 = i - x2
f[i][x1][x2] = max(f[i - 1][x1 - 1][x2] + w, f[i - 1][x1][x2 - 1] + w, f[i - 1][x1 - 1][x2 - 1] + w, f[i - 1][x1][x2](左边走过来)) 

*/

#include <bits/stdc++.h>

using namespace std;


int n, m;
int f[1010][55][55];
int w[55][55];

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        for (int j = 1;j <= m;j ++ ) {
            cin >> w[i][j];
        }
    }

    // memset(f, -0x3f, sizeof f);
    // f[2][1][1] = 0;
    for (int i = 2;i <= n + m;i ++ ) {
        for (int x1 = 1;x1 <= n;x1 ++ ) {
            for (int x2 = 1;x2 <= n;x2 ++ ) {
                int y1 =  i - x1, y2 = i - x2;
                if (y1 && y2 && y1 <= m && y2 <= m) {
                    if(x1 != x2 || i == 2 || i == n + m) {
                        int t = w[x1][y1] + w[x2][y2];    
                        int &x = f[i][x1][x2];            
                        x = max(x, f[i - 1][x1 - 1][x2 - 1] + t);
                        x = max(x, f[i - 1][x1 - 1][x2] + t);
                        x = max(x, f[i - 1][x1][x2 - 1] + t);
                        x = max(x, f[i - 1][x1][x2] + t);
                    }
                        
                }
                
            }
        }
    }
    printf("%d\n", f[n + m][n][n]);
}