#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n;
int p[N];
struct Edge
{
    int w;
    vector<int> e[2];
}edge[N];
int d[N][N], g[N][N];

int get(int a, int b)
{
    for (int j = 0; j < 2; j ++ )
        for (int k: edge[b].e[j])
            if (a == k)
                return b + j * n;
    return -1;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d", &n);
    for (int k = 0; k < n; k ++ )
    {
        int i;
        scanf("%d", &i);
        int id, cnt1, cnt2;
        scanf("%d%d%d", &edge[i].w, &cnt1, &cnt2);
        while (cnt1 -- )
        {
            scanf("%d", &id);
            edge[i].e[0].push_back(id);
        }
        while (cnt2 -- )
        {
            scanf("%d", &id);
            edge[i].e[1].push_back(id);
        }
    }

    for (int i = 1; i <= n * 2; i ++ ) p[i] = i;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < 2; j ++ )
        {
            for (int k: edge[i].e[j])
            {
                int a = i + j * n, b = get(i, k);
                p[find(a)] = find(b);
            }
        }

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n * 2; i ++ ) g[i][i] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int a = find(i), b = find(i + n);
        g[a][b] = g[b][a] = edge[i].w;
    }

    memcpy(d, g, sizeof d);
    int res = INF;
    for (int k = 1; k <= n * 2; k ++ )
    {
        for (int i = 1; i < k; i ++ )
            for (int j = i + 1; j < k; j ++ )
                res = min((long long)res, d[i][j] + (long long)g[j][k] + g[k][i]);
        for (int i = 1; i <= n * 2; i ++ )
            for (int j = 1; j <= n * 2; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    cout << res << endl;
    return 0;
}