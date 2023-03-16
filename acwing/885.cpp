#include <iostream>

using namespace std;

const int N = 2010, mod = 1e9 + 7;



int f[N][N];
int n;

void init()
{
    for (int i = 0;i < N;i ++ )
    for (int j = 0;j <= i;j ++ )
    {
        if (j == 0) f[i][j] = 1;
        else f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod; //选第 i 个与选第 i 个 
        
    }
}

int main()
{
    cin >> n;
    
    init();
    while (n -- )
    {
        int a, b; cin >> a >> b;
        cout << f[a][b] << endl;
    }
}