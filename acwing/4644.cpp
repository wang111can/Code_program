#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 2 * 1e5 + 10;

ULL a[N], s[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i ++ ) 
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ULL ans = 0;
    for (int i = 1;i <= n;i ++ )
    {
        ans += (s[n] - s[i]) * a[i];
    }
    cout << ans << endl;
    return 0;
}