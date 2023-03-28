#include <bits/stdc++.h>


using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    auto check = [&](int x) {
        while (x) {
            int t = x % 10;
            if (t == 1 || t == 2 || t == 9 || t == 0) {
                return true;
            }
            x /= 10;
        }
        return false;
    };
    for (int i = 1;i <= n;i ++ ) {
        if (check(i)) ans += i;
    }
    cout << ans << endl;
}