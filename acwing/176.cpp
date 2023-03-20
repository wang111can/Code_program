#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int C = 105;   //
const int N = 1005;  //
const int M = 20005; //

struct Point //
{
    int d, u, c;                        
    bool operator<(const Point &t) const
    {
        return d > t.d;
    }
};
int n, m;
int p[N], dist[N][C];             // 
int h[N], w[M], e[M], ne[M], idx; // 
bool st[N][C];                    // 

void add(int a, int b, int c) 
{
    e[++idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}


inline int dijkstra(int c, int start, int end)
{
    priority_queue<Point> heap;     
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);   
    heap.push((Point){0, start, 0}); 
    dist[start][0] = 0;              
    while (heap.size())
    {
        Point t = heap.top(); 
        heap.pop();
        if (t.u == end)
            return t.d; 
        if (st[t.u][t.c])
            continue;                              // 如果该点已经出队过，则跳过
        st[t.u][t.c] = true;                       // 记录该点已经出队过
        if (t.c < c)                               // 如果 t.c + 1 <= c，说明可以在该点加油，扩展一下加油的情况
            if (dist[t.u][t.c + 1] > t.d + p[t.u]) // 如果这次加油后的油钱比原来的低，
            {
                dist[t.u][t.c + 1] = t.d + p[t.u];                    // 那么更新原来的
                heap.push((Point){dist[t.u][t.c + 1], t.u, t.c + 1}); 
            }
        for (int i = h[t.u]; i; i = ne[i])      
            if (t.c >= w[i])                    
                if (dist[e[i]][t.c - w[i]] > t.d) // 如果这次到该点的油钱小于原来的
                {
                    dist[e[i]][t.c - w[i]] = t.d;             
                    heap.push((Point){t.d, e[i], t.c - w[i]}); //
                }
    }
    return -1; 
}

int main()
{
    scanf("%d%d", &n, &m); 
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]); 

    while (m--) 
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c); 
    }

    int T;
    scanf("%d", &T); 
    while (T--)      
    {
        int C, S, E;
        scanf("%d%d%d", &C, &S, &E);
        int d = dijkstra(C, S, E);
        if (d == -1)
            puts("impossible");
        else
            printf("%d\n", d);
    }

    return 0;
}
