#include <bits/stdc++.h>


using namespace std;

int tr[100010];
int n, a[100010], m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) tr[x] += y;
}

int ask(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        add(i, a[i]);
    }
    
    while (m -- ) {
        int k, l, r; cin >> k >> l >> r;
        if (k) {
            add(l, r);
        }
        else {
            cout << ask(r) - ask(l - 1) << endl;
        }
    }
}