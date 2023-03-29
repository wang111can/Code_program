#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Node {
    int l, r, v;
}tr[N * 4];
int n, a[N], m;

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[l]};
    }   
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r){
    int L = tr[u].l, R = tr[u].r;
    if (L >= l && R <= r) {
        return tr[u].v;
    }
    else {
        int mid = L + R >> 1;
        int res = 0;
        if (mid >= l) res = max(res, query(u << 1, l, r));
        if (mid < r) res = max(res, query(u << 1 | 1, l, r));
        return res;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    build(1, 1, n);
    
    while (m -- ) {
        int l, r; cin >> l >> r;
        cout << query(1, l, r) << endl;
    }
}