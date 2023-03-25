#include <iostream>

using namespace std;

const int N = 4010 , mod = 2147483648;
long f[N];
int n;


int main()
{
    cin >> n;

    f[0] = 1;
    for (int i = 1;i < n;i ++ )
        for (int j = i;j <= n;j ++ )
        {
            //if (f[i - 1][j] + f[i - 1][j - i] > 1)
                f[j]  = (f[j] + f[j - i]) % mod;
         }

    cout << f[n] % mod;

    return 0;
}
