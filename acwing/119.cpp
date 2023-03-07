#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10, mod = 16603;
const double INF = 1e18, eps = 1e-6;
struct Node
{
    double x, y;
    int type;
    int rd;
    bool operator<(const Node &nd)
    {
        if (fabs(x - nd.x) < eps)
            return rd < nd.rd;
        return x < nd.x;
    }
} point[N << 1], tmp[N << 1];
int T, n;
double mx = INF;
double th;
double dis(Node a, Node b)
{
    if (a.type == b.type)
        return mx;
    double dx = a.x - b.x, dy = a.y - b.y;
    double res = sqrt(dx * dx + dy * dy);
    mx = min(res, mx);
    return res;
}
double dfs(int l, int r)
{
    if (l >= r)
        return mx;
    int mid = l + r >> 1;
    double mid_x = point[mid].x;
    double res = min(dfs(l, mid), dfs(mid + 1, r));
    {
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (point[i].y <= point[j].y)
                tmp[k++] = point[i++];
            else
                tmp[k++] = point[j++];
        }
        while (i <= mid)
            tmp[k++] = point[i++];
        while (j <= r)
            tmp[k++] = point[j++];
        for (i = l, k = 0; i <= r; i++, k++)
            point[i] = tmp[k];
    }
    int k = 0;
    for (int i = l; i <= r; i++)
    {
        if (point[i].x > mid_x - res && point[i].x < mid_x + res)
            tmp[k++] = point[i];
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k && tmp[j].y - tmp[i].y < res; j++)
        {
            res = min(res, dis(tmp[i], tmp[j]));
        }
    }
    return res;
}
void solve()
{
    mx = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &point[i].x, &point[i].y);
        point[i].rd = rand() % 1000000;
        point[i].type = 0;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        scanf("%lf%lf", &point[i].x, &point[i].y);
        point[i].rd = rand() % 1000000;
        point[i].type = 1;
    }
    mx = min(mx, dis(point[1], point[2 * n]));
    sort(point + 1, point + 1 + 2 * n);
    printf("%.3lf\n", dfs(1, 2 * n));
}
int main()
{
    srand(0);
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
