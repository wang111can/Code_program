#include <bits/stdc++.h>

using namespace std;

int f[5010][5010];
int n;

int main() {
    cin >> n;
    vector<char> a; a.push_back(' ');
    for (int i = 1;i <= n;i ++ ) {
        char c; cin >> c;
        if (a.empty() || a.back() != c) {
            a.push_back(c);
        }
    }
    n = a.size() - 1;
    /*
    l r 
    从 l 开始 or 从 r 开始
    以 r 结束 or 以 l 结束
    a[l] != a[r]
    f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
    a[l] == a[r]
    f[l][r] = f[l + 1][r - 1] + 1;

    
    */
    for (int len = 2;len <= n;len ++ )  {

        for (int i = 1;i + len - 1 <= n;i ++ ) {
            int l = i, r = i + len - 1;
            f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
            if (a[l] == a[r]) {
                f[l][r] = min(f[l][r], f[l + 1][r - 1] + 1);
            }
            
        }
    }
    cout << f[1][n] << endl; 
    
}