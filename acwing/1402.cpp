// 记录形状 哈希 
// 使用 图形 内 点 两两之间的 距离作为hash 值


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int n, m;
char g[N][N];
PII q[N * N];
int top;

double get_dist(PII a, PII b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_hash()
{
    double res = 0;
    for (int i = 0; i < top; i ++ )
        for (int j = i + 1; j < top; j ++ )
            res += get_dist(q[i], q[j]);
    return res;
}

char get_id(double s)
{
    static double hash[N];
    static int cnt = 0;
    for (int i = 0; i < cnt; i ++ )
        if (fabs(s - hash[i]) < 1e-6)
            return i + 'a';
    hash[cnt ++ ] = s;
    return cnt - 1 + 'a';
}

void dfs(int a, int b)
{
    g[a][b] = '0';
    q[top ++ ] = {a, b};
    for (int x = a - 1; x <= a + 1; x ++ )
        for (int y = b - 1; y <= b + 1; y ++ )
            if (x != a || y != b)
            {
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1')
                    dfs(x, y);
            }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == '1')
            {
                top = 0;
                dfs(i, j);
                auto s = get_hash();
                char c = get_id(s);
                for (int k = 0; k < top; k ++ )
                    g[q[k].x][q[k].y] = c;
            }

    for (int i = 0; i < n; i ++ ) cout << g[i] << endl;
    return 0;
}