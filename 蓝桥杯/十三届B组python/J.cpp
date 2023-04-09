#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long i64;

const int N = 1e6 + 10, INF = 0x3f3f3f3f;

int n, k;
int a[N];
struct Node {
    int l, r;
    i64 s, minv, mark;
}tr[N << 2];

void pushup(Node tr[], int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].minv = min(tr[u << 1].minv, tr[u << 1 | 1].minv);
}

void build(Node tr[], int u, int l, int r) {
    tr[u] = {l, r, a[r], a[r], 0};
    if (l == r) return ;
    int mid = l + r >> 1;
    build(tr, u << 1, l, mid), build(tr, u << 1 | 1, mid + 1, r);
    pushup(tr, u);
}

void push(Node tr[], int u, int k) {
    tr[u].s += (tr[u].r - tr[u].l + 1) * k;
    tr[u].minv += k;
    tr[u].mark += k;
}

void pushdown(Node tr[], int u) {
    if (tr[u].mark) {
        push(tr, u << 1, tr[u].mark), push(tr, u << 1 | 1, tr[u].mark);
        tr[u].mark = 0;
    }
}

void update(Node tr[], int u, int l, int r, int k) {
    if (tr[u].l >= l && tr[u].r <= r) {
        push(tr, u, k);
        return ;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(tr, u);
    if (l <= mid) update(tr, u << 1, l, r, k);
    if (r > mid) update(tr, u << 1 | 1, l, r, k);
    pushup(tr, u);
}

i64 query(Node tr[], int u, int l, int r, int type) {
    if (tr[u].l >= l && tr[u].r <= r) return type ? tr[u].s : tr[u].minv;
    int mid = tr[u].l + tr[u].r >> 1;
    i64 res = type ? 0 : INF;
    pushdown(tr, u);
    if (l <= mid) res = query(tr, u << 1, l, r, type);
    if (r > mid) {
        i64 t = query(tr, u << 1 | 1, l, r, type);
        res = type ? res + t : min(res, t);
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    build(tr, 1, 1, n);

    i64 res = 0;
    for (int i = 1; i + k - 1 <= n; i ++ ) {
        i64 v = query(tr, 1, i, i + k - 1, 0);
        if (v > 0) {
            res += v;
            update(tr, 1, i, i + k - 1, -v);
        }
    }
    printf("%lld\n", res + query(tr, 1, 1, n, 1));

    return 0;
}
