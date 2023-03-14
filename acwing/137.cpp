#include <bits/stdc++.h>
using namespace std;

#define io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define x first
#define y second
#define fr front
#define db double
#define pb push_back
#define pi acos(-1) 
#define all(x) x.begin(), x.end()
mt19937_64 mrand(random_device{}());

typedef pair<int, int> PII;
typedef pair<double, double > PDD;
typedef long long ll ;
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18, p = 1e5+13;;

set<ll> st;
int a[12];

int get_() {
    int n = 6;
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (a[(i + k)] == a[(j + k)]) {
            k++;
        } else {
            a[(i + k)] > a[(j + k)] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    return min(i, j);
}

void solve() {
    int n; cin >> n;

    while (n -- ) {
        for (int i = 0;i < 6;i ++ ) {
            cin >> a[i]; a[i + 6] = a[i];
        }

        int k = get_();
        ll num = 1;
        for (int i = k;i <= 6 + k - 1;i ++ ) {
            num = num * 117 + a[i]; 
        }
        if (st.count(num)) {
            cout << "Twin snowflakes found.";
            return ;
        }
        else st.insert(num);
        reverse(a, a + 12);
        k = get_();
        num = 1;
        for (int i = k;i <= 6 + k - 1;i ++ ) {
            num = num * 117 + a[i];
        }
        if (st.count(num)) {
            cout << "Twin snowflakes found.";
            return ;
        }
        else st.insert(num);
    
    }
    cout << "No two snowflakes are alike.";
    
}   

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories