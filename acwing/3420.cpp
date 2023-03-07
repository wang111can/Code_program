#include <bits/stdc++.h>

using namespace std;

int ans;
set<string> st;

int n;
string str;

void dfs(string str, int u, int l, int r) {
    if (clock() / CLOCKS_PER_SEC > 0.9) {
        cout << max(ans, int(st.size())) << endl;
        exit(0);
    } 
    if (u == n) {
        int t = abs(l - r);
        if (l > r) {
            while (t-- )
                str += ')';
            st.insert(str);
            ans = max((int)st.size(), ans);
        }
        else {
            string tm; 
            while (t -- ) {
                tm += '(';
            }
            st.insert(tm + str);
            ans = max((int)st.size(), ans);
        }
    }
}


int main() {
    cin >> str;
    n = str.size();
    int l = 0, r = 0;
    for (auto x : str) {
        if (x  == '(') l ++ ;
        else r ++ ;
    }
    dfs(str, 0, l, r);
}