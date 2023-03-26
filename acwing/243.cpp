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

const int N = 1e5 + 10;

int a[N], n, m;
struct Node
{
    int l, r;
    LL sum, add; // sum表示区间 和, add 表示要下发给子区间每个数增加的值
}t[N * 4];

void pushup(int u)
{
    t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
}

void pushdown(int u)
{
    auto &fa = t[u], &l = t[u << 1], &r = t[u << 1 | 1];
    // 子传承父    
    //if (!fa.add) return ;

    l.sum += (l.r - l.l + 1) * fa.add;
    l.add += fa.add;
    
    r.sum += (r.r - r.l + 1) * fa.add;
    r.add += fa.add;
   // cout << fa.l << ' ' << fa.r << ' ' << fa.add  << ' ' << fa.sum << "   fa" << endl;
 //   cout << l.l << ' ' << l.r << ' ' << l.add << ' ' << l.sum << "   l"<< endl;
    //cout << r.l << ' ' << r.r << ' ' << r.add << ' ' << r.sum << "   r" << endl;
    fa.add = 0;
}

void build(int u, int l, int r)
{
    if (l == r) t[u] = {l, r, a[l], 0}; //每个单点的sum 为 他本身 add 为 0
    else
    {
        int mid = l + r >> 1;
        t[u] = {l ,r};
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v)
{
    if (t[u].l >= l && t[u].r <= r) // t[u] 被 l ~ r 包含 直接修改
    {
        
        t[u].sum += (t[u].r - t[u].l + 1) * v;
        t[u].add += v;
    } 
    else 
    {   
        // 没有直接被 l ~ r 包含 为了保证单个区间的add 只有一种状态 pushdown
        pushdown(u); //把但前区间要下发给子区间每个数增加的值 分发给子区间
        int mid = t[u].r + t[u].l >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
    
        pushup(u); //更新区间    
    }
}

LL query(int u, int l, int r)
{
    if (t[u].l >= l && t[u].r <= r)  return t[u].sum;
    else 
    {
        pushdown(u); // 没有直接被 l ~ r 覆盖 分发给子区间
        
        int mid = t[u].r + t[u].l >> 1;
        LL res = 0;
        
        if (l <= mid) res += query(u << 1, l, r);
        if (r > mid) res += query(u << 1 | 1, l, r);
        
        return res;
    } 
}


void solve()
{
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
        
    build(1, 1, n);
    /*
    C l r d，表示把 A[l],A[l+1],…,A[r] 都加上 d。
    Q l r，表示询问数列中第 l∼r 个数的和。
    */
    while (m -- )
    {
        char op[2]; int l, r;
        cin >> op >> l >> r;
        if (op[0] == 'C')
        {
            int d; cin >> d;
            modify(1, l, r, d);
        }
        else cout << query(1, l, r) << endl;
    }
    
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
