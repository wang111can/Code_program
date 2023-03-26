#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200010;
const LL INF = 1e18;

int n, m;
int a[N];
struct Node {
    int l, r;
    LL v, add;
}tr[N << 2];

void pushup(int u) {
    tr[u].v = min(tr[u << 1].v, tr[u << 1 | 1].v);
}

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.v += root.add;
        right.add += root.add, right.v += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) tr[u].v = a[r];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL v = INF;
    if (l <= mid) v = min(v, query(u << 1, l, r));
    if (r > mid) v = min(v, query(u << 1 | 1, l, r));

    return v;
}

void modify(int u, int l, int r, LL d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].v += d;
        tr[u].add += d;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    build(1, 0, n - 1);

    cin >> m;
    while (m -- ) {
        int l, r, d;
        char c;
        scanf("%d %d%c", &l, &r, &c);

        if (c == '\n') {
            if (l <= r) printf("%lld\n", query(1, l, r));
            else printf("%lld\n", min(query(1, l, n - 1), query(1, 0, r)));
        }
        else {
            scanf("%d", &d);
            if (l <= r) modify(1, l, r, d);
            else modify(1, l, n - 1, d), modify(1, 0, r, d);
        }
    }

    return 0;
}