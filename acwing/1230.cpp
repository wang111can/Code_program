#include <bits/stdc++.h>

using namespace std;

int  n, k;

int main() {
    cin >> n >> k;
    vector<long long> a(n + 1, 0);
    vector<long long> cnt(k + 1, 0);
    for (int i = 1;i <= n;i ++ ) cin >> a[i], a[i] = a[i - 1] + a[i];
    for (int i = 1;i <= n;i ++ ) a[i] = a[i] % k;
    long long ans = 0;
    cnt[0] = 1;
    for (int i = 1;i <= n;i ++ ) {
        ans += cnt[a[i]];
        cnt[a[i]] ++ ;
    }
    cout << ans << endl;
    return 0;
}