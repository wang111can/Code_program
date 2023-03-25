#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int a[N], tr[N], cnt[N], n;

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for ( ;x < N;x += lowbit(x)) tr[x] += y; 
}

int ask(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += tr[x];
    return res;
}


int main() {
    cin >> n;
    
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i]; a[i] ++ ;
    }
    for (int i = 1;i <= n;i ++ ) {
        cnt[i] += ask(N - 1) - ask(a[i]);
        add(a[i], 1);
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i;i -- ) {
        cnt[i] += ask(a[i] - 1);
        add(a[i], 1);
    }
    long long ans = 0;
    for (int i = 1;i <= n;i ++ ) ans += (1ll * cnt[i] * (1 + cnt[i]) / 2);
    cout << ans << endl;
    return 0;
}