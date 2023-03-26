#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int pivot, l = 0, r = 0; cin >> pivot;
    for (int i = 2;i <= n;i ++ ) {
        int a; cin >> a;   
        if (a > 0 && abs(a) < abs(pivot)) r ++ ;
        if (a < 0 && abs(a) > abs(pivot)) l ++ ;     
    }
    if ((pivot < 0 && r == 0) || (pivot > 0 && l == 0)) cout << 1;
    else cout << l + r + 1;
}