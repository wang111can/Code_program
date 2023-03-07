#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6;
int dx[N] = {-1, 0, 1, 0, 0}, dy[N] = {0, 1, 0, -1, 0};
char g[N][N], backup[N][N];


// 这个操作是把(x, y)以及上下左右的灯都变成相反的颜色
void turn (int x, int y)
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];

        //如果在边界外边，直接忽略即可
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;

        g[a][b] ^= 1;   //异或，不同的时候就变成相反的数
    }

}


int main()
{
    int n;
    scanf("%d", &n);
    while(n -- )
    {
        // 按行输入，把每一行当成一个字符串
        for (int i = 0; i < 5; i ++ ) cin >> g[i];

        int res = 10;

        // 这里我们枚举了第一行的32种按法，不用管是亮是灭，把第一行所有情况都按一遍
        // 按每种情况的第一行，去遍历接下来的行
        // 枚举32种第一行的按法只是可能会减少步数，如果直接从第二行开始答案一定是固定的了，找不到最优解或者可能没有解

        for (int op = 0; op < 32; op ++ )
        {
            // 我在对这种情况操作的时候，得先备用一下
            // 把原始数组备份一下，然后操作g，操作完了还原，然后再操作
            memcpy(backup, g, sizeof g);

            int step = 0;

            // 第一行的按法(在这里 1 表示按了, 0 表示不按)，这里只是为了输出第一行按完之后的状态
            for (int i = 0; i < 5; i ++ )
                if (op >> i & 1)  // 数字2 对应了 00010 表示第2个位置的按一下
                                  // 00010 >> 1 & 1  是1 所以turn(0, 1) 就是第一行第二个位置
                {                 // 数字3 对应了00011 表示第1 和第2个位置的按一下
                    step ++ ;
                    turn (0, i);;
                }

            // 然后通过第一行按完之后的状态，按234行
            for (int i =0; i < 4; i ++ )
                for (int j = 0; j < 5;j ++ )
                    if (g[i][j] == '0')
                    {
                        step ++;
                        turn (i + 1, j);  // 如果这个位置是灭的，就按下一行对应的位置
                    }

            bool dark = false;
            for (int j = 0; j < 5; j ++ )
                if (g[4][j] == '0')
                {
                    dark = true;
                    break;
                }


            // 对于32种情况的这一种，如果所有的全亮就记录下步数(事实上只记录了最后一行是否dark)
            if (!dark) res = min(res, step);
            memcpy (g, backup, sizeof g);
        }

        if(res > 6) res = -1;
        cout << res << endl;

    }
    return 0;
}
