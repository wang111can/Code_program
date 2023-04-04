#include <iostream>

#include <cmath>

using namespace std;

typedef long long LL ;

const int N = 2 * 1e5 + 10;

LL f[N][10];
int n;

int main()
{
    LL ans = 0;
    LL stk[10];
    int storey = 0;
    cin >> n;
    for (int i = 0;i < n;i ++ )
    {
        int top = 0;
        LL x; cin >> x;
        while (x > 1) stk[++ top] = x, x = sqrtl(x / 2 + 1);
        ans += top;
        storey = max(storey, top);
        for (int j = 0; top; ++ j, -- top)
            f[i][j] = stk[top];

    }
    
    for (int i = 0;i < storey;i ++ )
    for (int j = 1;j < n;j ++ )
        if (f[j][i] && f[j][i] == f[j - 1][i])  ans -- ;
        
    cout << ans << endl;
    
    return 0;
}

