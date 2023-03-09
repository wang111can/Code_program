#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

pair<int, int> dot[10010];
int a[10010], b[10010];
int n;
bool st[20010];

int main() {

    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i] >> b[i];
        a[i] += 10000, b[i] += 10000;
        dot[i] = {a[i], b[i]};   
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1;i <= n;i ++ ) a[i] -= i; // 偏移量
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int res = 0;
    for (int i = 1;i <= n;i ++ ) {
        res += abs(a[i] - a[(n + 1) / 2]);
        res += abs(b[i] - b[(n + 1) / 2]);
    }
    cout << res << endl;

    return 0;

}