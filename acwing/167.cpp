#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100;

int w[N], len, n, sum;
bool st[N];


bool cmp(int x, int y)
{
    return x > y;
}



bool dfs(int u, int s, int idx)
{
    if (u * len == sum) return true;
    if (s == len) return dfs(u + 1, 0, 0);
    
    for (int i = idx;i < n;i ++ )
    {
        if (st[i]) continue;
        if (s + w[i] > len) continue;
        
        st[i] = true;
        if (dfs(u, s + w[i], idx + 1)) return true;
        st[i] = false;
        
        if (s == 0 || s + w[i] == len) return false;
        
        int j = i + 1;
        while (j < n && w[i] == w[j]) j ++ ;
        i = j - 1;
    }
    
    return false;
    
    
}


int main()
{

    while (cin >> n, n)
    {
         sum = 0;
        memset(st, 0, sizeof st);
        for (int i = 0;i < n;i ++ ) 
        {
            cin >> w[i];
            sum += w[i];
        }
        
        sort(w, w + n, cmp);
        
        len = w[0];
        while (1)
        {
            if (sum % len == 0 && dfs(1, 0, 0))
            {
                cout << len << endl;
                break;
            }
            len ++ ;
        }
    }
    
    
    return 0;
}