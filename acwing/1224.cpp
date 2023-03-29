/*
a[i] != i
while(a[i] != i)swap(a[i], a[a[i]])  // 每次 把 a[i] 上 的 数 放到 应该 放的 位置
该解 为 最优 解
若 某一次 交换 a[i], a[a[i]]  之外 的 位置 
必然 会比 直接 交换 a[i] a[a[i]] 的 次数 大 


*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, ans = 0; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i<= n;i ++ ) cin >> a[i];
    for (int i = 1;i <= n;i ++ ) {
        while (a[i] != i) {
            swap(a[i], a[a[i]]);
            ans ++ ;
        }
    }
    cout << ans << endl;
}