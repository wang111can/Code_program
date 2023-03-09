/*
设每个人 分出 去 的 糖果为 x
x1 + x2 + x3 + x4 + x5 最小 
a1 - x1 + x5 = d
a2 - x2 + x1 = d
a3 - x3 + x2 = d
a4 - x4 + x3 = d
a5 - x5 + x4 = d

d = (a1 + a2 + ... + an) * 1 / n

x1 = xn - (d - a1)
x2 = xn - (2d - a1 - a2)
...
...
xn = xn - (nd - a1 - a2 - .. - an) 

即求
xn - (d - a1) + 
xn - (2d - a1 - a2) + 
...
+ xn


xn - c0
xn - c1
xn - c2 
c0 c1 c2 .. cn 与 xn 出于 同一直线

*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1000010;

int n;
LL a[N];

int main()
{
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sum /= n;
    for (int i = n; i > 1; i -- )
    {
        a[i] = a[i] - sum + a[i + 1];
    }
    a[1] = 0;
    sort(a + 1, a + n + 1);

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res += abs(a[i] - a[(n + 1) / 2]);
    cout << res << endl;

    return 0;
}