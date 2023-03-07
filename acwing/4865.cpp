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

const int N = 2e5 + 10;

int n;
string ans;
string s;

void in(){

    if (cin >> s) {
        ans += s;
        if (s == "pair") {
            ans += '<';
            in();
            ans += ',';
            in();
            ans += '>';
        }
    }
    else {
        cout << "Error occurred";
        exit(0);
    }
}

void solve() {
    cin >> n;
    in();
    if (cin >> s) {
        cout << "Error occurred" << endl;
    }
    else cout << ans << endl;

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
