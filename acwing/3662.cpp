/*
可以 得出 
f[i] 表示 已 第 a[i] 结尾 的 最大上升子序列 和
f[i] = max(f[i], (f[k]... f[k + x]) (满足a[k] .. a[k + x] 严格 < a[i]) + a[i])
我们 将 a[] 离散化  得到 g[] 使用 树状数组 维护 g[]
res = max(f[g[]])
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;



ll n, a[N], f[N], g[N], tr[N * 4];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, ll y) {
    for (int i = x;i <= n;i += lowbit(i)) tr[i] = max(tr[i], y);
}

ll ask(int x) {
    ll res = 0;
    for (int i = x; i;i -= lowbit(i)) res = max(res, tr[i]);
    return res;
}




int main() {
    cin >> n;
    vector<int> v;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1;i <= n;i ++ ) {
        int t = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        f[i] = max(a[i], ask(t - 1) + a[i]);
        add(t, f[i]);
    }
    cout << *max_element(f + 1, f + 1 + n) << endl;

}