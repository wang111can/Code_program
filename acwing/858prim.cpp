#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 600, M = 10e5 + 10;

int h[N][N];
int dist[M];
bool st[N];
int n, m;

int prim()
{
    memset(dist, 0x3f, sizeof dist); 
    int res = 0;
    for (int i = 0; i < n; i++)
    { 
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == 0x3f3f3f3f)
            return 0x3f3f3f3f;
        if (i)
            res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], h[j][t]); 
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;
    memset(h, 0x3f, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        h[a][b] = h[b][a] = min(h[a][b], w);
    }

    int t = prim();
    if (t == 0x3f3f3f3f)
        cout << "impossible";
    else
        cout << t;

    return 0;
}
