#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;


/*
把 相同 符号 的 段 合并 
这样 就 变成 了 从 正 数 段 里 选 不超过 k 段 的 方案

我们 可以 一开始 选 所有 正 段 
然后 删 掉 cnt  - k 条 

*/
typedef long long ll;

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

int a[N], b[N];
int l[N], r[N], n, m;
bool st[N];

int main() {

    cin >> n >> m;
    int k = 1;
    
    for (int i = 1;i <= n;i ++ ) {
        int x; cin >> x;
        if (1ll * b[k] * x < 0) b[++ k] = x;
        else b[k] += x;
        
    }
    
    n = k;
    k = 0;
    int ans = 0;
    for (int i = 1;i <= n;i ++ ) {
        if (b[i] > 0) {
            ans += b[i]; k ++ ;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  q;
    for (int i = 1;i <= n;i ++ ) {
        l[i] = i - 1, r[i] = i + 1;
        q.push({abs(b[i]), i});
        
    }

    // b[0] = b[n] = inf;

    auto op = [&](int x) {
        st[x] = true;
        l[r[x]] = l[x];
        r[l[x]] = r[x];
     };

    while (k > m) {
        while (st[q.top().y]) q.pop();

        auto t = q.top(); q.pop();
        if (l[t.y] != 0 && r[t.y] != n + 1 || b[t.y] > 0) {
            k -- ;
            ans -= t.x;
            int left = l[t.y], right = r[t.y];
            b[t.y] = b[left] + b[right] + b[t.y];
            q.push({abs(b[t.y]), t.y});
            op(left), op(right);
        }   
        else op(t.y);
 
 
    }
    cout << ans << endl;



}