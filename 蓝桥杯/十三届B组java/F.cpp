#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100, M = 1e5 + 10;

int n, m, limit;
int w[N][M];
struct Node
{
    int l, r;
    int maxv, minv;
}tr[M * 40];
int root[N], idx;

int build(int c[], int l, int r)
{
    int p = ++ idx;
    tr[p].maxv = tr[p].minv = c[r];
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(c, l, mid), tr[p].r = build(c, mid + 1, r);
    tr[p].maxv = max(tr[tr[p].l].maxv, tr[tr[p].r].maxv);
    tr[p].minv = min(tr[tr[p].l].minv, tr[tr[p].r].minv);
    return p;
}


void get(int i, int a, int b, int& maxv, int& minv)
{
    for ( ; a <= b; a ++ )
        maxv = max(maxv, w[a][i]), minv = min(minv, w[a][i]);
}

void query(int p, int l, int r, int ls, int rs, int& maxv, int& minv)
{
    if (l >= ls && r <= rs) 
    {
        maxv = max(maxv, tr[p].maxv);
        minv = min(minv, tr[p].minv);
        return ;
    }
    int mid = l + r >> 1;
    if (ls <= mid) query(tr[p].l, l, mid, ls, rs, maxv, minv);
    if (rs > mid) query(tr[p].r, mid + 1, r, ls, rs, maxv, minv);
}

void update(int a, int b, int l, int r, int& maxv, int& minv)
{
    maxv = 0, minv = 1e9;
    if (l > r) return ;
    for (; a <= b; a ++ ) query(root[a], 1, m, l, r, maxv, minv);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ ) 
            scanf("%d", &w[i][j]);
        root[i] = build(w[i], 1, m);    
    }

    scanf("%d", &limit);

    int res = 0;
    for (int a = 1; a <= n; a ++ )
        for (int b = a; b <= n; b ++ )
            for (int i = 1, j = 1, maxv = 0, minv = 1e9; i <= m; i ++ )
            {
                get(i, a, b, maxv, minv);
                while (j <= i && maxv - minv > limit) update(a, b, ++ j, i, maxv, minv);
                res = max(res, (i - j + 1) * (b - a + 1));
            }

    printf("%d\n", res);

    return 0;        
}

