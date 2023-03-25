#include <bits/stdc++.h>

/*
f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - 1][k - (p[i] - q[i])] + p[i] + q[i])
*/
using namespace std;

const int N = 210, M = 810, base = 400;

int n, m;
int p[N], d[N];
int f[N][21][M];
int ans[N];

int main()
{
    int T = 1;
    while (scanf("%d%d", &n, &m), n || m) {
        for (int i = 1; i <= n; i ++ ) scanf("%d%d", &p[i], &d[i]);

        memset(f, -0x3f, sizeof f);
        f[0][0][base] = 0;

        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j <= m; j ++ )
                for (int k = 0; k < M; k ++ ) {
                    f[i][j][k] = f[i - 1][j][k];
                    int t = k - (p[i] - d[i]);
                    if (t < 0 || t >= M || j < 1) continue;
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + p[i] + d[i]);
                }

        int v = 0;
        while (f[n][m][base - v] < 0 && f[n][m][base + v] < 0) v ++ ;

        if (f[n][m][base - v] > f[n][m][base + v]) v = base - v;
        else v = base + v;
        int cnt = 0, i = n, j = m, k = v;
        while (j) {
            if (f[i][j][k] == f[i - 1][j][k]) i -- ;
            else {
                ans[cnt ++ ] = i;
                k -= (p[i] - d[i]);
                i --, j -- ;
            }
        }

        int sp = 0, sd = 0;
        for (int i = 0; i < cnt; i ++ ) {
            sp += p[ans[i]];
            sd += d[ans[i]];
        }

        printf("Jury #%d\n", T ++ );
        printf("Best jury has value %d for prosecution and value %d for defence:\n", sp, sd);

        sort(ans, ans + cnt);
        for (int i = 0; i < cnt; i ++ ) printf(" %d", ans[i]);
        puts("\n");
    }

    return 0;
}
