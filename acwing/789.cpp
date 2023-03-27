#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1;i <= n;i ++ ) cin >> a[i];
    
    while (q -- ) {
        int k; cin >> k;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (a[l] == k) {
            int t = l;
            l = 1, r = n;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= k) l = mid;
                else r = mid - 1;
            }
            cout << t - 1 << ' ' << r - 1 << endl;
        }
        else cout << "-1 -1" << endl;
    }
    
}