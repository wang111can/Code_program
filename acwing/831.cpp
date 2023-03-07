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

const int N = 1e7 + 10;

char s[N], p[N];
int ne[N], n, m;

void solve() {
    cin >> n >> (p + 1) >> m >> (s + 1);
    for (int i = 2, j = 0;i <= n;i ++ ) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    for (int i = 1, j = 0;i <= m;i ++ ) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) {
            j ++ ;
        }
        if (j == n) {
            cout << i - n << ' ';
            j = ne[j];
        }
    }


}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
