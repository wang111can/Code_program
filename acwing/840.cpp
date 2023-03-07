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


int p[N];

int find(int x) {
    int k = (x % N + N) % N;
    while (p[k] != 0x3f3f3f3f && p[k] != x) {
        if (k == N) k = 0;
        k ++ ;
    }
    return k;
}

void solve() {
    memset(p, 0x3f, sizeof p);
    int n; cin >> n;
    while (n -- ) {
        char op; int x;
        cin >> op >> x;
        if (op == 'I'){
            p[find(x)] = x;
        }
        else {
            if (p[find(x)] != 0x3f3f3f3f) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
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
