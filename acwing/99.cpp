#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, m;
int s[N][N];

int main()
{
    cin >> m >> n;
    n = min(5001, n);
    
    while (m -- )
    {
        int x, y, w; cin >> x >> y >> w;
        s[ ++ x][ ++ y] += w;
    }
    

    for (int i = 1;i <= 5001;i ++ )
    for (int j = 1;j <= 5001;j ++ )
        s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + s[i][j];
    
    int ans = 0;
     for (int i = n;i <= 5001;i ++ ) // 要使结果尽可能大 从 r, r 开始
        for (int j = n;j <= 5001;j ++ )
            ans = max(ans, s[i][j] + s[i - n][j - n] - s[i - n][j] - s[i][j - n]);
    
    cout << ans << endl;

    
    return 0;
}