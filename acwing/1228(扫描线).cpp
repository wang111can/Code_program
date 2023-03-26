#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> vx;
vector<array<int, 4>> event;
int n, m;

struct info {
    int minv, cnt; // 区间 出现的 最小值 与 出现 次数
};

info operator +(const info &l, const info &r) { 
    info a;
	a.minv = min(l.minv, r.minv);
	if (l.minv == r.minv) a.cnt = l.cnt + r.cnt;
	else if (l.minv < r.minv) a.cnt = l.cnt;
	else a.cnt = r.cnt;
	return a;
}

struct Node {
    int tag;
    info val;
}tr[201000 * 8];

void pushup(int u) {
	tr[u].val = tr[u << 1].val + tr[u << 1 | 1].val;
}

void settag(int u, int t) {
	tr[u].val.minv = tr[u].val.minv + t;
	tr[u].tag = tr[u].tag + t;
}

void pushdown(int u) {
	if (tr[u].tag != 0) {
		settag(u << 1, tr[u].tag);
		settag(u << 1 | 1, tr[u].tag);
		tr[u].tag = 0;
	}
}

void modify(int u, int l, int r, int ql, int qr, ll t) {
	if (l == ql && r == qr) {
		settag(u, t);
		return;
	}
	int mid = (l + r) / 2;
	pushdown(u);
	if (qr <= mid) modify(u * 2, l, mid, ql, qr, t);
	else if (ql > mid) modify(u * 2 + 1, mid + 1, r, ql,qr, t);
	else {
		modify(u * 2, l, mid, ql, mid, t);
		modify(u * 2 + 1, mid + 1, r, mid + 1, qr, t);
	}
	pushup(u);
} 

void build(int u, int l, int r) {
	if (l == r) {
		tr[u].val = {0, vx[r] - vx[r - 1]}; // 段 长
	} else {
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}


int main() {

    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        vx.push_back(x1), vx.push_back(x2); // 离散化
        event.push_back({y1, 1, x1, x2});
        event.push_back({y2, -1, x1, x2}); // 线段 增加 删除 操作
    }

	sort(event.begin(), event.end());
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    
    m = vx.size() - 1; // 段数 
    build(1, 1, m);
    int prey = 0; // 上一个 y 坐标
    int totlen = tr[1].val.cnt; // 段 的 出现 次数
    int ans = 0;  
    for (auto e : event) {
        // 没有 被 覆盖 了 
        int cov  = totlen; // 覆盖 的 次数
        if (tr[1].val.minv == 0)  cov = totlen - tr[1].val.cnt; 
        ans += (e[0] - prey) * (cov);
        prey = e[0];
        int x1 = lower_bound(vx.begin(), vx.end(), e[2]) - vx.begin() + 1;
        int x2 = lower_bound(vx.begin(), vx.end(), e[3]) - vx.begin(); // 左右 端点
        if (x1 > x2) continue;
        modify(1, 1, m, x1, x2, e[1]); // 加上 还是 删除     
    }

    cout << ans << endl;

    return 0;
}