#include <string>
#include <iostream>
using namespace std;

int main ()
{
    string a, b; cin >> a >> b;
    for (int i = 0; i < a.size(); i ++ )
        for (int j = 0; j < b.size(); j ++ )
            for (char k = '0'; k <= '2'; k ++ )
            {
                string ra = a; ra[i] ^= 1;
                string rb = b; if (b[j] == k) continue; rb[j] = k;
                int x = 0, y = 0;
                for (int i = 0; i < ra.size(); i ++ ) x = x * 2 + ra[i] - '0';
                for (int i = 0; i < rb.size(); i ++ ) y = y * 3 + rb[i] - '0';
                if (x == y) return cout << x << endl, 0;
            }
    return 0;
}