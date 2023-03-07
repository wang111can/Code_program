
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int h[N], e[N], ne[N], d[N], idx;
int q[N];
int S[N];

struct Edge
{
    int x, y;
}edges[N];

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
bool topsort()  //拓扑排序
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i, S[i] = tt;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j, S[j] = tt;
        }
    }
    return tt == n - 1;
}
void solve()
{
    scanf("%d%d", &n, &m);

    idx = 0;
    memset(d,  0, (n + 1) * 4);
    memset(h, -1, (n + 1) * 4);

    for (int i = 0; i < m; ++ i)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t) add(a, b), ++ d[b];
        edges[i] = {a, b};
    }
    if (!topsort()) puts("NO");
    else
    {
        puts("YES");
        for (int i = 0; i < m; ++ i)
        {
            auto &t = edges[i];
            if (S[t.x] < S[t.y]) printf("%d %d\n", t.x, t.y);
            else printf("%d %d\n", t.y, t.x);
        }
    }
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T -- ) solve();
    return 0;
}
