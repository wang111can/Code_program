#include <bits/stdc++.h>

#define x first
#define y second
#define inf 0x3f3f3f3f

using namespace std;

const int N = 100010;

pair<int, int> p[N];
pair<int, int> mec[N];
int n, m;


int main() {
    
    while (cin >> n >> m) {

        for (int i = 1;i <= n;i ++ ) {
            cin >> mec[i].x >> mec[i].y;

        }
        for (int i = 1;i <= m;i ++ ) {
            cin >> p[i].x >> p[i].y;
        }

        sort(mec + 1, mec + 1 + n, greater<pair<int, int>>());
        sort(p + 1, p + 1 + m, greater<pair<int, int>>());
        
        // for (int i = 1;i <= m;i ++ ) {
        //     cout << p[i].x << ' ' << p[i].y << endl;
        // }
        long long ans = 0, cnt = 0;
        multiset<int> st;
        for (int i = 1, j = 1;i <= m;i ++ ){

            while (j <= n && p[i].x <= mec[j].x) st.insert(mec[j ++ ].y);
            multiset<int>::iterator x = st.lower_bound(p[i].y);
           
            if (x != st.end()){
                cnt ++ ;
                ans += 500 * p[i].x + 2 * p[i].y;
                st.erase(x);
            }
        }
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}