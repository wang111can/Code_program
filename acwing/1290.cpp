#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL ;
typedef unsigned long long ULL;

LL n, m, mod = 100003 ;

LL get_(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve()
{
    cin >> m >> n;
    
    // 对于越狱可能数
    // path = 全部方案数 m ^ n - 不越狱方案数 m * (m - 1) * ... * (m - 1)
    

    LL all = get_(m, n);
    LL unescape = get_(m - 1, n - 1) * m % mod;
    cout << (all - unescape + mod) % mod << endl;
}

int main()
{
	io;
    int T; T = 1 ;
    while (T -- )
    {
        solve();
    }
	return 0;
}
