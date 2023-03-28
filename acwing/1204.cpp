#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int a[N];

int main()
{
    int cnt;
    cin >> cnt;
    string line;

    getline(cin, line); // 忽略掉第一行的回车
    while (cnt -- )
    {
        getline(cin, line);
        stringstream ssin(line);

        while (ssin >> a[n]) n ++ ;
    }

    sort(a, a + n);

    int res1, res2;
    for (int i = 1; i < n; i ++ )
        if (a[i] == a[i - 1]) res2 = a[i];  // 重号
        else if (a[i] >= a[i - 1] + 2) res1 = a[i] - 1; // 断号

    cout << res1 << ' ' << res2 << endl;

    return 0;
}