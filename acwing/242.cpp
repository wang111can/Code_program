#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> PII;
typedef long long LL ;
typedef unsigned long long ULL;

const int N = 1e5 + 10;

int n, m;
int tr[N], a[N];

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


void solve()
{
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ )
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]); // 差分树状数组
    }
    
    while (m -- )
    {
        char c; cin >> c;
        if (c == 'C') 
        {
            int l, r, t; cin >> l >> r >> t;
            add(l, t), add(r + 1, -t);
        }
        else 
        {
            int t; cin >> t;
            cout << sum(t) << endl;
        }
    }
        
}

int main()
{
    int T; T = 1 ;
    while (T -- )
    {
        solve();
    }
	return 0;
}



