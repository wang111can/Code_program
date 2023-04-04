#include <bits/stdc++.h>
// f[i] 表示 以第 i 个 元素 结尾 的 最长 子序列 g[i] 表示 以 a[i] 开头 的 最长 子序列
// f[i - k] + k + g[j] a[j] >= a[i - k]
// ans = max(↑, f[i] + k, g[i] + k)


using namespace std;

const int N = 1e5 + 10;
int n, m, k, ans;
int a[N], b[N], dp1[N], dp2[N];   
int find(int x) 
{
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (b[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
struct
{
    int maxv;
} seg[N * 4];
void pushup(int id)
{
    seg[id].maxv = max(seg[id << 1].maxv, seg[id << 1 | 1].maxv);
}
void build(int id, int l, int r)
{
    if (l == r)
        seg[id].maxv = 0;
    else
    {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
}
void change(int id, int l, int r, int pos, int val)
{
    if (l == r)
        seg[id].maxv = max(seg[id].maxv, val);
    else
    {
        int mid = l + r >> 1;
        if (pos <= mid)
            change(id << 1, l, mid, pos, val);
        else
            change(id << 1 | 1, mid + 1, r, pos, val);
        pushup(id);
    }
}
int query(int id, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
        return seg[id].maxv;
    int mid = l + r >> 1;
    if (qr <= mid)
        return query(id << 1, l, mid, ql, qr);
    else if (ql >= mid + 1)
        return query(id << 1 | 1, mid + 1, r, ql, qr);
    else
        return max(query(id << 1, l, mid, ql, mid), query(id << 1 | 1, mid + 1, r, mid + 1, qr));
}
signed main()
{

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1); 
    if (n == k)
    {
        cout << n << '\n';
        return 0;
    } 
    m = 1;
    for (int i = 2; i <= n; i++) 
        if (b[i] != b[m])
            b[++m] = b[i];
    for (int i = 1; i <= n; ++i)
        a[i] = find(a[i]);
    build(1, 1, m); 
    for (int i = 1; i <= n - k; ++i)
    {
        dp1[i] = query(1, 1, m, 1, a[i]) + 1;
        change(1, 1, m, a[i], dp1[i]);
    }
    build(1, 1, m); 
    for (int i = n; i >= k + 1; --i)
    {

        dp2[i] = query(1, 1, m, a[i], m) + 1;        
        ans = max(ans, dp1[i - k] + k + query(1, 1, m, a[i - k], m));
        change(1, 1, m, a[i], dp2[i]);
    }

    for (int i = 1; i <= n - k; ++i)
        ans = max(ans, dp1[i] + k);
    for (int i = n; i >= k + 1; --i)
        ans = max(ans, dp2[i] + k);
    cout << ans << '\n';
    return 0;
}
