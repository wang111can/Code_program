#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;
string a , b ;
int res ;

int main()
{
    cin >> a >> b ;
    for(int i = 0 ; i < a.size() ; i ++)
    {
        if(a[i] != b[i])
        {
            res ++ ;
            if(b[i + 1] == 'o') b[i + 1] = '*' ;
            else b[i + 1] = 'o' ;
        }
    }
    cout << res << endl ;
    return 0 ;
}
