#include <iostream>

using namespace std;

const int N = 110;

int ans[N];
int n;

bool dfs(int u, int deep)
{
    if (u > deep) return false;
    if (ans[u - 1] == n) return true;
    
    bool st[N] = {0};
    
    for (int i = u - 1;i >= 0;i -- )
        for (int j = i;j >= 0;j -- )
        {
            int s = ans[i] + ans[j];
            if (st[s]) continue; 
            if (s <= ans[u - 1] || s > n) continue;

            st[s] = true;
            
            ans[u] = s;
            if (dfs(u + 1, deep)) return true;
        }
    
    return false;
    
}

int main()
{
    ans[0] = 1;
    while (cin >> n, n)
    {
        int deep = 1;
        while (!dfs(1,deep)) deep ++ ;
        
        for (int i = 0;i < deep;i ++ ) cout << ans[i] << ' ';
        cout << endl;
    }
    
    return 0;
}

