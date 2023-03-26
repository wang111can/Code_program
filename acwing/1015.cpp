#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int h[N][N];

int f[N][N];
int t;

int main()
{
    cin >> t;
    while (t -- )
    {
        memset(h,0,sizeof h);
        int a,b;
        cin >> a >> b;
        for (int i = 1;i <= a;i ++ )
            for (int j = 1;j <= b; j ++ ) 
                cin >> h[i][j];
                
        for (int i = 1;i <= a;i ++ )
            for (int j = 1;j <= b;j ++ )
                f[i][j] = max(f[i - 1][j],f[i][j - 1]) + h[i][j];
        cout << f[a][b] << endl;
        
    }
}
