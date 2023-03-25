#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

typedef long long LL;

int n;
int a[N];
int tr[N];
LL ans1, ans2;
LL up[N], low[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)  // 位置x加c
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)  // 返回前x个数的和
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}


int main()
{
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    for (int i = 1;i <= n;i ++ )
    {
        // 
        up[i] = sum(n) - sum(a[i]); // 左边比当前数大的
        low[i] = sum(a[i] - 1);
        add(a[i], 1);
    }
    
    memset(tr, 0, sizeof tr);
    for (int i = n; i;i -- )
    {
        ans1 += up[i] * 1ll * (sum(n) - sum(a[i]));
        ans2 += low[i] * 1ll * (sum(a[i] - 1));
        add(a[i], 1);
    }
    
    cout << ans1 << ' ' << ans2 << endl;
    
    return 0;
}