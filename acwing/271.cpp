#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll f[35][35][35][35][35]; // f[a][b][c][d][e] 表示 a b c d e 人 的 方案
int times[10];



int main() {
    int n;
    while (cin >> n, n) {
        memset(times, 0, sizeof times);
        for (int i = 1;i <= n;i ++ ) cin >> times[i];
        f[0][0][0][0][0] = 1;
        for (int a = 0;a <= times[1];a ++ ) {
            for (int b = 0;b <= min(a, times[2]);b ++ ) {
                for (int c = 0;c <= min(b, times[3]);c ++ ) {
                    for (int d = 0;d <= min(c, times[4]);d ++ ) {
                        for (int e = 0;e <= min(d, times[5]);e ++ ) {
                            
                            ll &x = f[a][b][c][d][e];
                            if(a || b || c || d || e ) x = 0;
                            if (a && a - 1 >= b) x += f[a - 1][b][c][d][e];
                            if (b && b - 1 >= c) x += f[a][b - 1][c][d][e];
                            if (c && c - 1 >= d) x += f[a][b][c - 1][d][e];
                            if (d && d - 1 >= e) x += f[a][b][c][d - 1][e];
                            if (e) x += f[a][b][c][d][e - 1];
                        }
                    }
                }    
            }
        }
        cout << f[times[1]][times[2]][times[3]][times[4]][times[5]] << endl;
    }

}