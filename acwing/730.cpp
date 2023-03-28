#include <bits/stdc++.h>

using namespace std;

int n, h[100010];


bool check(int mid) {
    for (int i = 1;i <= n;i ++ ) {
        mid = mid * 2 - h[i];
        if (mid >= 1e5) return true;
        if (mid < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++ ) cin >> h[i];
    int l = 0, r = 1e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;

}