#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010, M = 10;
/*
搜索顺序
1 3 3 3 2
6 1 7 2 7
6 4 1 5 8
6 2 8 1 8
2 4 8 5 1

*/
int n, m;
int primes[N], cnt;
bool st[N];
vector<int> c1[M], c3[M], c15[M][M], c124[M][M][M];
int g[6][6];
vector<string> ans;

int get(int x, int k)
{
    int t = 1;
    for (int i = 0; i < 5 - k; i ++ ) t *= 10;
    return x / t % 10;
}

void init()
{
    for (int i = 2; i < N; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i < N; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        if (p < 10000 || p > 99999) continue;
        int n1 = get(p, 1), n2 = get(p, 2), n3 = get(p, 3), n4 = get(p, 4), n5 = get(p, 5);
        if (n1 + n2 + n3 + n4 + n5 != n) continue;
        c1[n1].push_back(p);
        c3[n3].push_back(p);
        if (n2 && n3 && n4)
            c15[n1][n5].push_back(p);
        c124[n1][n2][n4].push_back(p);
    }
}

bool check(int x1, int y1, int x2, int y2)
{
    int s = 0;
    for (int i = x1; i <= x2; i ++ )
        for (int j = y1; j <= y2; j ++ )
        {
            int x = g[i][j];
            if (x < 0 || x > 9) return false;
            s = s * 10 + x;
        }
    return !st[s];
}

void dfs(int u)
{
    if (u > 7)
    {
        g[3][5] = n - g[3][1] - g[3][2] - g[3][3] - g[3][4];
        g[4][5] = n - g[1][5] - g[2][5] - g[3][5] - g[5][5];
        g[4][3] = n - g[4][1] - g[4][2] - g[4][4] - g[4][5];
        g[5][3] = n - g[5][1] - g[5][2] - g[5][4] - g[5][5];

        if (check(1, 3, 5, 3) && check(1, 5, 5, 5) && check(3, 1, 3, 5) &&
            check(4, 1, 4, 5) && check(5, 1, 5, 5))
        {
            string s;
            for (int i = 1; i <= 5; i ++ )
                for (int j = 1; j <= 5; j ++ )
                    s += to_string(g[i][j]);
            ans.push_back(s);
        }
        return;
    }
    if (u == 1)
    {
        for (auto x: c1[g[1][1]])
        {
            g[2][2] = get(x, 2), g[3][3] = get(x, 3), g[4][4] = get(x, 4), g[5][5] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 2)
    {
        for (auto x: c3[g[3][3]])
        {
            g[5][1] = get(x, 1), g[4][2] = get(x, 2), g[2][4] = get(x, 4), g[1][5] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 3)
    {
        for (auto x: c15[g[1][1]][g[1][5]])
        {
            g[1][2] = get(x, 2), g[1][3] = get(x, 3), g[1][4] = get(x, 4);
            dfs(u + 1);
        }
    }
    else if (u == 4)
    {
        for (auto x: c124[g[1][2]][g[2][2]][g[4][2]])
        {
            g[3][2] = get(x, 3), g[5][2] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 5)
    {
        for (auto x: c124[g[1][4]][g[2][4]][g[4][4]])
        {
            g[3][4] = get(x, 3), g[5][4] = get(x, 5);
            dfs(u + 1);
        }
    }
    else if (u == 6)
    {
        for (auto x: c15[g[1][1]][g[5][1]])
        {
            g[2][1] = get(x, 2), g[3][1] = get(x, 3), g[4][1] = get(x, 4);
            dfs(u + 1);
        }
    }
    else
    {
        for (auto x: c124[g[2][1]][g[2][2]][g[2][4]])
        {
            g[2][3] = get(x, 3), g[2][5] = get(x, 5);
            dfs(u + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    init();

    g[1][1] = m;
    dfs(1);

    if (ans.empty()) puts("NONE");
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i ++ )
        {
            for (int j = 0; j < 25; j ++ )
            {
                cout << ans[i][j];
                if ((j + 1) % 5 == 0) cout << endl;
            }
            if (i + 1 < ans.size()) cout << endl;
        }
    }

    return 0;
}
