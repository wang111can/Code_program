#include <iostream>

using namespace std;
using ll = long long;


ll n, ans;

int main() {
    cin >> n;
    while (n) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << endl;
}