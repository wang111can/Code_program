#include<bits/stdc++.h>
using namespace std;

int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
set<int> res;

bool check(int year, int month, int day)
{
    if (month == 0 || month > 12) return false;
    if(((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) days[2] = 29;
    if (day > days[month] || day  <= 0) return false;
    days[2] = 28;
    return true;
}

void calc(int y, int m, int d)
{
    if(y >= 60)
        y = 1900 + y;
    else
        y = 2000 + y;
    if(check(y, m, d))
        res.insert(y * 10000 + m * 100 + d);
}

int main()
{
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    calc(a, b, c);
    calc(c, a, b);
    calc(c, b, a);

    for(auto t : res)
        printf("%d-%02d-%02d\n", t / 10000, t % 10000 / 100, t % 100);
    return 0;
}
