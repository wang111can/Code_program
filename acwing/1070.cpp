#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int d1[N], d2[N], p1[N], up[N];
int maxd;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs_d(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            dfs_d(j, u);
            int distance = d1[j] + 1;
            if (distance > d1[u])
            {
                d2[u] = d1[u], d1[u] = distance;
                p1[u] = j;
            }
            else if (distance > d2[u]) d2[u] = distance;
        }
    }

    maxd = max(maxd, d1[u] + d2[u]);
}

void dfs_u(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            up[j] = up[u] + 1;
            if (p1[u] == j) up[j] = max(up[j], d2[u] + 1);
            else up[j] = max(up[j], d1[u] + 1);
            dfs_u(j, u);
        }
    }
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs_d(0, -1);
    dfs_u(0, -1);

    for (int i = 0; i < n; i ++ )
    {
        int d[3] = {d1[i], d2[i], up[i]};
        sort(d, d + 3);
        if (d[1] + d[2] == maxd) printf("%d\n", i);
    }

    return 0;
}
