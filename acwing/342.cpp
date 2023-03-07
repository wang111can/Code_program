
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII ;
const int N = 25010, M = 50000 * 4 + 10, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx, dist[N], n, m1, m2, s;
bool st[N];
int id[N], ud;// 每个点的编号
vector<int> block[N]; // 连通块
int in[N]; // 每个连通块的入度


void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void dfs(int u, int uid)
{
    id[u] = uid;
    block[uid].push_back(u);
    
    for (int i = h[u]; ~i ;i = ne[i])
    {
        int t = e[i];
        if (!id[t]) dfs(t, uid);
    }
    
}
queue<int> q;

void dijkstra(int u)
{
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        
        for (auto i : block[u])
            heap.push({dist[i], i});
        
        while (heap.size())
        {
            auto t = heap.top(); heap.pop();
            int dot = t.second, dis = t.first;
            if (st[dot]) continue;
            st[dot] = true;
            
            
            for (int i = h[dot]; ~ i;i = ne[i])
            {
                int j = e[i];
                if (id[j] != id[dot] && -- in[id[j]] == 0) q.push(id[j]);
                if (dist[j] > dist[dot] + w[i])
                {
                    dist[j] = dist[dot] + w[i];
                    if (id[j] == id[dot]) heap.push({dist[j], j});
                } 
            }
        }
}

void compute()
{
   // priority_queue<PII, vector<PII>, greater<PII>> q;
    
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    for (int i = 1;i <= ud;i ++ )
        if (!in[i]) q.push(i);

    
    
    while (q.size())
    {
        int t = q.front(); q.pop();
        dijkstra(t);
    }
    
    

}




int main()
{
    cin >> n >> m1 >> m2 >> s;
    memset(h, -1, sizeof h);
    while (m1 -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    for (int i = 1;i <= n;i ++ ) if (!id[i]) dfs(i, ++ ud); // 如果当前点没有进入连通块则 加入连通块
    
    while (m2 -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        in[id[b]] ++ ; // 增加入度
        add(a, b, c);
    }
    
    
     compute();
    
    for (int i = 1;i <= n;i ++ )
        if (dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    
    
    return 0;
    
}
