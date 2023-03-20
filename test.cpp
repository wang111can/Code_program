#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

int cnt[M], mp[M];// 分别求每一个状态对应的1 的个数 与 状态对应的值
int c[N], r[N], g[3][3]; // 行列九宫格可用状态
char str[100];

void init()
{
    for (int i = 0;i < N;i ++ ) c[i] = r[i] = M - 1;

    for (int i = 0;i < 3;i ++ )
    for (int j = 0;j < 3;j ++ )
        g[i][j] = M - 1;
}

void draw(int x, int y, int t, bool flag)
{
    // 画点
    if (flag) str[x * N + y] = t + '1';
    else str[x * N + y] = '.';
    
    
    // 更改状态
    int v = 1 << t;
    if (!flag) v = -v;
    
    c[x] -= v;
    r[y] -= v;
    g[x / 3][y / 3] -= v;
}

int get_state(int x, int y)// 返回 行列九宫格里的 & 集
{
    return c[x] & r[y] & g[x / 3][y / 3];
}

int lowbit(int x)  // 返回末尾的1
{
    return x & -x;
}


bool dfs(int t)
{
    if (!t) return true;
    
    int x, y, sta = 10;// 优先从可选点数最小开始枚举
    for (int i = 0;i < N;i ++ )
    for (int j = 0;j < N;j ++ )
        if (str[i * N + j] == '.')
        {
            int state = get_state(i, j);
            if (cnt[state] < sta )
            {
                sta = cnt[state];
                x = i;
                y = j;
            }
        }
        
    int state = get_state(x, y);
    // 以二进制序列从低位到高位依次枚举数
    for (int i = state; i; i -= lowbit(i))
    {
        int z = mp[lowbit(i)];
        draw(x, y, z, true);
        if (dfs(t - 1)) return true;
        draw(x, y, z, false);
        
    }
    
    return false;
}

int main()
{
    //预处理
    for (int i = 0;i < N;i ++ ) mp[1 << i] = i;
    for (int i = 0;i < M;i ++ )
        for (int j = 0;j < N;j ++ )
            cnt[i] += (i >> j) & 1;
    
    while (cin >> str, str[0] != 'e')
    {
        init();
        
        int cn = 0;
        for (int i = 0, k = 0;i < N;i ++ )
            for (int j = 0;j < N;j ++ ,k ++ )
                if (str[k] == '.') cn ++ ;
                else 
                {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
        
        dfs(cn);
        
        cout << str << endl;

    }

    return 0;
}