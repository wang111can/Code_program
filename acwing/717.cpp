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

ll a[100];
int n;
void solve() {
cin >> n;
    a[2] = 1;
    for (int i = 1;i <= n;i ++ ) {
        if (i == 1) 
            cout << a[0] << ' ' ;
        else if (i == 2) {
            cout << a[i] << ' '; 
        }
        else{
            
        a[i] = a[i - 1] + a[i - 2];
        cout << a[i] << ' ' ;
    
        }}
}

int main() {
	io; int T; T = 1;
    while (T -- ){
        solve();
    }
	return 0;
}
