#include <iostream>

using namespace std;

const int sz = 1010;
int a[sz][sz], b[sz][sz];
int n, m, q;

void inset(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            inset(i, j, i, j, a[i][j]);
        }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        inset(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0;
}