#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL ;
typedef unsigned long long ULL;

const int N = 2010, M = 1000100; // M = (500 + 500) * 1000 

int h[N], ne[M], w[M], e[M], idx;
int n, m, cnt, level[N], d[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, d[b] ++ , h[a] = idx ++ ;
}

void tsort()
{
    queue<int> q;
    for (int i = 1;i <= n;i ++ )
        if (!d[i]) q.push(i);
        
    while (q.size())
    {
        int t = q.fr(); q.pop();
        
        for (int i = h[t]; ~i;i = ne[i])
        {
            int j = e[i];
            d[j] -- ;
            if (!d[j])
            {
                level[j] = level[t] + w[i];
                q.push(j);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1;i <= m;i ++ )
    {
        memset(st, 0, sizeof st);
        int t; cin >> t;
        
        int sta = n, ed = 1;
        while (t -- )
        {
            int a; cin >> a;
            sta = min(a, sta);
            ed = max(a, ed);
            st[a] = true;
        }
       
        int dot = n + i; // 虚拟点
        level[dot] = 0;

        // 对于在 与 不在 停靠车站中的点 A, B  A >= B + 1
        for (int j = sta;j <= ed;j ++ )
            if (!st[j]) // 不在停的车站中 
                add(dot, j, 0); // i -> dot
            else  // 在车站中
                add(j, dot, 1); // dot -> i
        
    }
    
    for (int i = 1;i <= n;i ++ ) level[i] = 1;// 牌子等级最低为一
  
     tsort();

    int ans = 0;
    for (int i = 1;i <= n;i ++ ) ans = max(level[i], ans);
    
    cout << ans << endl;
}

int main()
{
	io;
    int T; T = 1;
    while (T -- )
    {
        solve();
    }
	return 0;
}



