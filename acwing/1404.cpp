#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 130;

int n;
int g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int ans;

void dfs(int x, int y, int d, int k)
{
    if (!x || x > n || !y || y > n || g[x][y]) return;
    stack<PII> stk;
    while (x && x <= n && y && y <= n && !g[x][y])
    {
        g[x][y] = 2;
        stk.push({x, y});
        x += dx[d], y += dy[d];
        k ++ ;
    }
    ans = max(ans, k);
    if (!x || x > n || !y || y > n || g[x][y] == 1)
    {
        x -= dx[d], y -= dy[d];
        for (int i = 0; i < 4; i ++ )
            if ((i + d) % 2)
                dfs(x + dx[i], y + dy[i], i, k);
    }

    while (stk.size())
    {
        auto t = stk.top();
        stk.pop();
        g[t.x][t.y] = 0;
    }
}

int main()
{
    int m;
    cin >> n >> m;
    while (m -- )
    {
        char a;
        int b;
        cin >> a >> b;
        a = a - 'A' + 1;
        g[b][a] = 1;
    }
    dfs(1, 1, 1, 0);
    dfs(1, 1, 2, 0);
    cout << ans << endl;
    return 0;
}