#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

ll mod = 5000011;
ll f[N], s[N];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    f[0] = s[0] = 1; 
    // f[i] = f[i - k - 1] + f[i - k - 2] + ... + f[1] + f[0]
    // f[i] 表示 当前 位 取 1 的方案
    for (int i = 1;i <= n;i ++ )  {
        f[i] = s[max(0, i - k - 1)];
        s[i] = (s[i - 1] + f[i]) % mod;
    }
    cout << s[n] << endl;

    return 0;
}