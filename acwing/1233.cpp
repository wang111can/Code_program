#include <iostream>
#include <queue>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

char g[N][N];
bool st[N][N];
int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool check(int xx, int yy)
{
    for (int i = 0;i < 4;i ++ )
    {
        int a = xx + dx[i], b = yy + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] == '.') return false;
    }
    
    return true;
    
}

bool bfs(int xx, int yy)
{
    queue<PII> q;
    q.push({xx, yy});
    //cout << yy << ' ' << xx << endl;
    vector<int> res;
    
    while (q.size())
    {
        auto t = q.front(); q.pop();
        
        for (int i = 0;i < 4;i ++ )
        {
            int a = dx[i] + t.x, b = dy[i] + t.y;
            if (a >= 0 && a < n && b >= 0 && b < n && !st[a][b] && g[a][b] == '#')
            {
                if (check(a, b))
                {
                    res.push_back(1);
                    //cout << a << ' ' << b << endl;
                    
                }
                st[a][b] = true;
                q.push({a, b});
            }
        }
    }
    
    if (!res.size()) return true;
    return false;
}


int main()
{
    cin >> n;
    for (int i = 0;i < n;i ++ ) cin >> g[i];
    

    int ans = 0;
    for (int i = 0;i < n;i ++ )
        for (int j = 0;j < n;j ++ )
            if (!st[i][j] && g[i][j] == '#')
            {
                if (bfs(i, j))
                    ans ++ ;
            }
            else if (g[i][j] == '.')st[i][j] = true;
            
    cout << ans << endl;
    
    return 0;
}