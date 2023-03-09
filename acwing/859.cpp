#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int p[N], n, m;

struct edge
{
    int a, b, c;
    bool operator < (edge & x)
    {
        return c < x.c;
    }
}g[N];

int find(int x)  // 并查集
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    cin >> n >> m;
    
    for (int i = 0;i < m;i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[i] = {a, b, c};
    }
    
    sort(g, g + m);
    for (int i = 1;i <= n;i ++ ) p[i] = i;
    int ans = 0, cnt  = 0;
    
    for(int i = 0;i < m;i ++ )
    {
        int a = g[i].a, b = g[i].b, c = g[i].c;
        int x1 = find(a), x2 = find(b);
        if (x1 != x2)
        {
            // cout << x1 << ' ' << x2 << endl;
            p[x1] = x2;
            cnt ++ ;
            ans += c;
        }
    }
    
    if (cnt < n - 1) cout << "impossible\n";
    else cout << ans << endl;
    
    return 0;
 }
