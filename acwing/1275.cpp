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

const int N = 8e5 + 10;

struct Node
{
    int l, r, v;
    
}tr[N];
int m, p;

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v); 
}

void build(int u, int l, int r)
{
    tr[u] = {l ,r};
    if (l == r) return ;
    else
    {
        int mid = (l + r) / 2 ;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u,int x, int q)
{
    if (tr[u].l == tr[u].r) tr[u].v = q;
    else 
    {
        int mid = (tr[u].l + tr[u].r) / 2 ;
        if (x <= mid) modify(u << 1, x, q); 
        else modify(u << 1 | 1, x, q); 
    
        pushup(u); 
    }
}

int ask(int u, int l, int r)
{
    if (tr[u].r <= r && tr[u].l >= l) return tr[u].v;
    
    int mid = (tr[u].r + tr[u].l) / 2;
    int res = 0;
    if (l <= mid) res = ask(u << 1, l, r);
    if (r > mid) res = max(ask(u << 1 | 1, l, r), res);
    
    return res;
     
}

void solve()
{
    cin >> m >> p;
    build(1, 1, m); // 区间 1 ~ m 建树
    
    int last = 0, l = 0;
    while (m -- )
    {
        char op[2]; int t;
        cin >> op >> t;
        if (op[0] == 'A')
        {
            modify(1, ++ l, (LL)(1LL * last + t) % p);
        }
        else 
        {
            last = ask(1, l - t + 1, l) ;
            cout << last << endl;
        }
    }
}

int main()
{
	io;
    int T; T = 1;
    while (T -- )
    {
        solve();
    }
	return 0;
}
