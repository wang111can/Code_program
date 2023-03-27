#include <bits/stdc++.h>

using namespace std;
const double eps = 0.000000001;

int main() {
    double n; cin >> n;

    double l = -10000, r = 10000;
    while (abs(r - l) >  eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%0.6lf", l);
}