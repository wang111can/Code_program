#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 50010, M = 999997;

int n, m;
struct Circle
{
    int x, y, r;
}cir[N];
LL h[M];
int id[M];
bool st[M];

LL get_key(int x, int y)
{
    return x * 1000000001ll + y;
}

int find(int x, int y)
{
    LL key = get_key(x, y);
    int t = (key % M + M) % M;

    while (h[t] != -1 && h[t] != key)
        if ( ++ t == M)
            t = 0;
    return t;
}

int sqr(int x)
{
    return x * x;
}

void dfs(int x, int y, int r)
{
    st[find(x, y)] = true;

    for (int i = x - r; i <= x + r; i ++ )
        for (int j = y - r; j <= y + r; j ++ )
            if (sqr(i - x) + sqr(j - y) <= sqr(r))
            {
                int t = find(i, j);
                if (id[t] && !st[t])
                    dfs(i, j, cir[id[t]].r);
            }
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        cir[i] = {x, y, r};

        int t = find(x, y);
        if (h[t] == -1) h[t] = get_key(x, y);

        if (!id[t] || cir[id[t]].r < r)
            id[t] = i;
    }

    while (m -- )
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);

        for (int i = x - r; i <= x + r; i ++ )
            for (int j = y - r; j <= y + r; j ++ )
                if (sqr(i - x) + sqr(j - y) <= sqr(r))
                {
                    int t = find(i, j);
                    if (id[t] && !st[t])
                        dfs(i, j, cir[id[t]].r);
                }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        if (st[find(cir[i].x, cir[i].y)])
            res ++ ;

    printf("%d\n", res);
    return 0;
}

