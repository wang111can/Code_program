#include <iostream>

using namespace std;

int n;

int get_min(string &str) {
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (str[i + k] == str[j + k]) k ++ ;
        else {
            if (str[i + k] > str[j + k]) {
                i = i + k + 1;
            }
            else j = j + k + 1;
            if (i == j) i ++ ;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {
    string a, b;
    cin >> a >> b;
    n = a.size();
    a += a, b += b;
    a += b, b += b;
    int x = get_min(a), y = get_min(b);
    a = a.substr(x, n), b = b.substr(y, n);

    if (a == b) {
        cout << "Yes" << endl;
        cout << a << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}