#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;
typedef pair<int, int> PII;
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
unordered_set<int> vis[N];
int dist[N];
bool st[N];
int next(int x, int t)
{
    int cnt = 0;
    while (vis[x].count(t))
        t++, cnt++;
    return cnt;
}
int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    while (heap.size())
    {
        int t = heap.top().second;
        heap.pop();
        if (st[t])
            continue;
        st[t] = true;
        int nw = next(t, dist[t]);
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i] + nw)
            {
                dist[j] = dist[t] + w[i] + nw;
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n];
}
int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            vis[i].insert(x);
        }
    }
    int ans = dijkstra();
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}