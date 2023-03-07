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
    int n; string str; cin >> n >> str;
    for (auto &x : str) {
        x = tolower(x);
    }
    string goal = "meow";
    string ans;
    ans += str[0];
    for (auto x : str) {
        if (ans.back() != x) {
            ans += x;
        }
    }
    if (ans == goal) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}

int main() {
	io; int T; cin >> T;
    while (T -- ){
        solve();
    }
	return 0;
}
