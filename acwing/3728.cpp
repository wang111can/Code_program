#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;

int n, m, p[N];
int x[N], y[N], k[N];
struct Edge
{
    int a, b;
    ll c;
    inline bool operator<(const Edge &t) const
    {
        return c < t.c;
    }
} edge[N * N];
int cnt;
bool st[N * N]; 

int find(int x)
{
    return x != p[x] ? p[x] = find(p[x]) : x;
}

ll kruskal()
{
    ll res = 0;
    sort(edge, edge + cnt);
    for (int i = 0; i < cnt; ++i)
    {
        int a = find(edge[i].a), b = find(edge[i].b);
        if (a != b)
        {
            p[a] = b;
            res += edge[i].c;
            st[i] = true;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int c;
        scanf("%d", &c);
        edge[cnt++] = {i, 0, c};
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", k + i);
        for (int j = 1; j < i; ++j) 
            edge[cnt++] = {i, j, (ll)(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
    }
    printf("%lld\n", kruskal());
    vector<int> v;             
    vector<pair<int, int>> es; 
    for (int i = 0; i < cnt; ++i)
        if (st[i])
            if (!edge[i].b)
                v.push_back(edge[i].a);
            else
                es.push_back({edge[i].a, edge[i].b});
    printf("%d\n", v.size());
    for (int &x : v)
        printf("%d ", x);
    printf("\n%d\n", es.size());
    for (auto &[x, y] : es)
        printf("%d %d\n", x, y);
    return 0;
}
