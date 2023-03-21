#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int g[N], path[5][N];
int n;

int f()
{
    int cnt = 0;
    for (int i = 0;i + 1 < n;i ++ )
        if (g[i + 1] != g[i] + 1) cnt ++ ;
    return (cnt + 2) / 3;
}

bool dfs(int u, int deep)
{
    if (u + f() > deep) return false;
    if (!f()) return true;
    
    for (int l = 0;l < n;l ++ )
        for (int r = l;r < n;r ++  ) // 依次枚举区间
            for (int k = r + 1;k < n;k ++ ) // 枚举区间可以插入的位置
            {
                memcpy(path[u], g, sizeof g) ;
                
                int y = l; 
                for (int i = r + 1;i <= k;i ++ ,y ++ ) g[y] = path[u][i];
                for (int i = l; i <= r;i ++ , y ++ ) g[y] = path[u][i];
                if (dfs(u + 1,deep)) return true;
                
                memcpy(g, path[u], sizeof g) ;
                
            }
    
    return false;
    
}


int main()
{
    int T; cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0;i < n;i ++ ) cin >> g[i];
        
        int deep = 0;
        while (deep < 5 && !dfs(0, deep)) deep ++ ;
        
        if (deep == 5) cout << "5 or more\n";
        else cout << deep << "\n";
    }
    
    return 0;
}

