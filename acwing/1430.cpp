#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (!st[a][b])
            cnt ++ ;
    }
    return cnt <= 1;
}

int dfs(int x, int y, int u)
{
    if (x == n && y == 1)
    {
        if (u == n * n) return 1;
        return 0;
    }

    if (st[x - 1][y] && st[x + 1][y] && !st[x][y - 1] && !st[x][y + 1] ||
        st[x][y - 1] && st[x][y + 1] && !st[x - 1][y] && !st[x + 1][y])
        return 0;

    int cnt = 0, sx, sy;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (!(a == n && b == 1) && !st[a][b] && check(a, b))
        {
            cnt ++ ;
            sx = a, sy = b;
        }
    }

    int res = 0;
    if (cnt > 1) return 0;
    else if (cnt == 1)
    {
        st[sx][sy] = true;
        res += dfs(sx, sy, u + 1);
        st[sx][sy] = false;
    }
    else
    {
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (!st[a][b])
            {
                st[a][b] = true;
                res += dfs(a, b, u + 1);
                st[a][b] = false;
            }
        }
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i ++ )
        st[i][0] = st[i][n + 1] = st[0][i] = st[n + 1][i] = true;

    st[1][1] = true;
    cout << dfs(1, 1, 1) << endl;
    return 0;
}