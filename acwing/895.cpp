#include <bits/stdc++.h>

using namespace std;

int f[1010], a[1010];
int n;

int main(){
    cin >> n;
    for (int i = 1;i <= n;i ++ ) {
        cin >> a[i];    
    }
    for (int i = 1;i <= n;i ++ ) {
        f[i] = 1;
        for (int j = 1;j < i;j ++ ) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    cout << *max_element(f + 1, f + 1 + n);
    
}