#include <bits/stdc++.h>

#define x first 
#define y second

using namespace std;

/*
要求 消灭 每个 怪兽
我们 可以 对 每个 怪兽 求 一个 他前面 的 附带伤害 的 值 然
sum = 剩余血量和  可以知道 该 值 是 固定 的 
最后 求出 一个 最小 的 点 开始 然后 加上 以该点 为 起点 + sum 
*/

int a[200010], b[200010];

int main() {
    int n; cin >> n;

    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i] >> b[i];
    }

    int sum = 0;
    for (int i = 1;i <= n;i ++ ) {
        if (i == 1) {
            sum += max(0, a[1] - b[n]);
        }
        else sum = 
    }


}