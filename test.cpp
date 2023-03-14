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

int n = 6;
int a[] = {0, 3, 9, 12, 5, 18, 4, 3, 9, 12, 5, 18, 4};
int ans = inf;

void work(int u) {
    int sum = 0, now = 0;
    int cnt = 0, last = u;
    vector<int> sub(n * 3, 0); 
    for (int i = u;i <= u + n - 1;i ++ ) {
        cnt ++ ;
        if (now < a[i]) {
            sub[i] = a[i] - now;
            sum += sub[i];
            now += sub[i];        
        }

        if (cnt > 1) {
            now -= sub[last]; last ++ ;
        }
    }
    ans = min(ans, sum);
}


void solve() {
    for (int i = 1;i <= n;i ++ ) {
        work(i);
    }
    cout << ans << endl;
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
//  --allow-unrelated-histories