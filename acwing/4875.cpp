#include <bits/stdc++.h>


using namespace std;

int main()
{
    int t; cin >> t;
    while (t -- ) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1;i <=  n;i ++ ) {
            cin >> a[i];
        }
        if (*min_element(a.begin() + 1, a.end()) == a[1]) {
            cout << "Bob" <<endl;
        }
        else cout << "Alice" << endl;
    }
    return 0;
}