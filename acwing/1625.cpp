#include <bits/stdc++.h>

using namespace std;

// 可以 发现 与 y 没关系
int tr[32010], n, ans[32010];

inline int lowbit(int x) {
    return x & -x;
}

int ask(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}

void add(int x, int y) {
    for (;x < 32010;x += lowbit(x)) tr[x] += y;
}


int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int x, y; cin >> x >> y;
        x ++ ;
        ans[ask(x)] ++ ;
        add(x, 1);
    }
    for (int i = 0;i < n;i ++ ) cout << ans[i] << endl;
    return 0;
}
