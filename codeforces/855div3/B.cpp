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
typedef unsigned long long ULL;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    string str; cin >> str;
    map<char, int> mp;
    set<char> st;
    for (auto x:str) {
        mp[x] ++ ;
        st.insert(tolower(x));
    }
    int ans = 0;
    for (auto x : st) {
        int maxv = max(mp[toupper(x)], mp[x]);
        int t = abs(mp[toupper(x)] - mp[x]);
        ans += (maxv - t);
        while (t > 1&& k) {
            k -- ;
            ans ++ ;
            t -= 2;
        } 
    }
    cout << ans << endl;

}

int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
