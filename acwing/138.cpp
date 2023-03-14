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
const ll INF = 1e18;

int x = 27;
int n, m;
ull s[1000010], p[1000010];
char str[1000010];

ull get_(int r, int l) {
    return s[r] - s[l - 1] * p[r - l + 1];
} 

void solve() {
    p[0] = 1;
    cin >> str + 1;
    n = strlen(str + 1);
    for (int i = 1;i <= n;i ++ ) {
        s[i] = s[i - 1] * x + str[i] - 'a' + 1;
        p[i] = p[i - 1] * x;
    }    
    cin >> m;

    while (m -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        ull l = get_(b, a), r = get_(d, c);
        
        if (l == r) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }

}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories