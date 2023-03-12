#include <iostream>
#include <limits.h>

using namespace std;

const int N = 1000010;

int stkl[N], stkr[N], topl, topr;
int f[N], sum[N];

void add(int x)
{
    stkl[ ++ topl] = x;
    sum[topl] = sum[topl - 1] + x;
    f[topl] = max(f[topl - 1], sum[topl]);
}

int main()
{
    int n;
    scanf("%d", &n);
    char ops[2];
    f[0] = INT_MIN;
    while (n -- )
    {
        int x;
        scanf("%s", ops);
        if (*ops == 'I')
        {
            scanf("%d", &x);
            add(x);
        }
        else if (*ops == 'D')
        {
            if (topl) topl -- ;
        }
        else if (*ops == 'L')
        {
            if (topl) stkr[ ++ topr] = stkl[topl -- ];
        }
        else if (*ops == 'R')
        {
            if (topr) add(stkr[topr -- ]);
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", f[x]);
        }
    }
    return 0;
}
